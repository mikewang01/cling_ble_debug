#include "bluegiga_controller.h"
#include "Qobject.h"
#include <QDialog>

#define MAX_DEVICES 64
int found_devices_count = 0;
bd_addr found_devices[MAX_DEVICES];

enum actions {
    action_none,
    action_scan,
    action_connect,
    action_info,
};
enum actions action = action_none;

typedef enum {
    state_disconnected,
    state_connecting,
    state_connected,
    state_finding_services,
    state_finding_attributes,
    state_listening_measurements,
    state_finish,
    state_last
} states;
states state = state_disconnected;

const char *state_names[state_last] = {
    "disconnected",
    "connecting",
    "connected",
    "finding_services",
    "finding_attributes",
    "listening_measurements",
    "finish"
};

#define FIRST_HANDLE 0x0001
#define LAST_HANDLE  0xffff

#define CLING_BLE_DEBUG_SERVICE_UUID    0x5500
#define CLING_BLE_DEBUG_TX_UUID         0x5504
#define CLING_BLE_DEBUG_RX_UUID         0x5505
//D1:55:03:7D:40:0E
uint8 primary_service_uuid[] = {0x00, 0x28};

uint16 thermometer_handle_start = 0,
       thermometer_handle_end = 0,
       thermometer_handle_measurement = 0,
       thermometer_handle_configuration = 0;

bd_addr connect_addr;


BlueGiga_controller* BlueGiga_controller::p_instance = NULL;
BlueGiga_controller* BlueGiga_controller::get_instance(int com_num)
{

    if(BlueGiga_controller::p_instance == NULL){
        BlueGiga_controller::p_instance = new BlueGiga_controller(0, "COM" +  QString::number(com_num));
    }

    BlueGiga_controller::p_instance->activateWindow();
    return BlueGiga_controller::p_instance;
}

BlueGiga_controller::BlueGiga_controller(QWidget *parent, QString serial_port): QDialog(parent), serial_port_used(NULL),
    current_status(comm_unkhnown),serial_port_name(serial_port)
{
    if(BlueGiga_controller::open_serial() == true){
         qDebug()<<serial_port_name<<":opened sucessfully";
    }else{
         qDebug()<<serial_port_name<<":parameter error";
    }
    //QObject::connect(serial_port_used,  SIGNAL(error(QSerialPort::SerialPortError)), this , SLOT(serial_error_slot(QSerialPort::SerialPortError)));
    BlueGiga_controller::connect(serial_port_used,  SIGNAL(readyRead()),this, SLOT(slot_read_serial()));
    //BlueGiga_controller::write_serial((char*)"hello mike", sizeof("hello mike"));
    ble_ui = new Ui_ble_conn_dialog();
    ble_ui->setupUi(this);
    this->setLayout(ble_ui->gridLayout);
    this->show();
    /*link actual phy send method to ble protocol*/
    BlueGiga_controller::set_ble_control_phy_output();

    connect(ble_ui->pushButton_ble_connect , SIGNAL(clicked()) , this , SLOT(push_button_ble_connect_slot()));
    connect(ble_ui->pushButton_ble_disconnect , SIGNAL(clicked()) , this , SLOT(push_button_ble_disconnect_slot()));
    connect(ble_ui->pushButton_addmac , SIGNAL(clicked()) , this , SLOT(push_button_ble_add_mac_slot()));
    connect(ble_ui->pushButton_ble_log_clear , SIGNAL(clicked()) , this , SLOT(push_button_log_clear_slot()));

}

BlueGiga_controller::~BlueGiga_controller(){
    BlueGiga_controller::serial_port_used ->close();
    qDebug()<<"serial closed";
}
/*dialog closed event*/
void BlueGiga_controller::closeEvent(QCloseEvent *event)
{
    qDebug()<<"closed event";
    delete BlueGiga_controller::p_instance;
    BlueGiga_controller::p_instance = NULL;
}
/*============================slot parts===============================*/
void BlueGiga_controller::push_button_ble_connect_slot(){

    qDebug()<<"cpush_button_ble_connect_slot";
    reset_ble_state_machine();
    ble_cmd_system_reset(0);
    sleep(500);
    this->close_serial();
    if(check_serail_eixsted()==false){
        qDebug()<<"com not found";
    }
    this->open_serial();
    QString mac_address_selected = ble_ui->comboBox_mac_select->currentText();
    QByteArray ba = mac_address_selected.toLatin1();
    str_to_mac((const char*)ba.data(),connect_addr.addr);
    char str[256];
    sprintf(str, "Trying to connect0x%02x:0x%02x", (uint8)connect_addr.addr[0], (uint8)connect_addr.addr[1]);
    qDebug()<<str;

    ble_debug(QString::asprintf("%s",str));
    qDebug()<<QString::asprintf( "Trying to connect0x%02x:0x%02x", (uint8)connect_addr.addr[2], (uint8)connect_addr.addr[3]);
    ble_cmd_gap_connect_direct(&connect_addr, gap_address_type_random, 40, 60, 100,0);
        //ble_cmd_system_get_info();

}

void BlueGiga_controller::push_button_ble_disconnect_slot(){
    qDebug()<<"push_button_ble_disconnect_slot";
}
void BlueGiga_controller::push_button_ble_add_mac_slot(){

    QString mac_address_entered = ble_ui->lineEdit_mac_addr->text();
    if(mac_address_entered.size() == ble_ui->comboBox_mac_select->currentText().size()){
        qDebug()<<"add sucessfully";
        ble_ui->comboBox_mac_select->addItem(mac_address_entered);
        ble_ui->comboBox_mac_select->setCurrentIndex(1);
    }else{
        qDebug()<<"add failed";
    }
    QByteArray ba = mac_address_entered.toLatin1();
    str_to_mac((const char*)ba.data(),connect_addr.addr);
    qDebug()<<"push_button_ble_add_mac_slot";
}
void BlueGiga_controller::push_button_log_clear_slot(){
    ble_ui->textEdit_ble_log->clear();
    qDebug()<<"push_button_log_clear_slot";
}
/*********************************************************************
 * @fn        void device::open_serial()
 *
 * @brief   slot function ,when recieve specifc signal ,open coresponded comm port
 *
 * @param   none
 *
 * @return   none
 */

bool BlueGiga_controller::check_serail_eixsted(){
    int i = 0;
    while(i < 10){
        /*add serial information to combom box*/
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            qDebug() << info.portName();
            if(info.portName() == serial_port_name){
                qDebug() << "find it " << serial_port_name;
                return true;
            }
        }
        sleep(100);
        i++;
    }
    return false;
}

bool BlueGiga_controller::close_serial(){
   this ->serial_port_used->close();
   this-> current_status = comm_closed;
}

bool BlueGiga_controller::open_serial()
{

    if(this-> current_status == comm_closed || this-> current_status == comm_error|| this-> current_status == comm_unkhnown )
    {
        if(this ->serial_port_used == NULL){
            this ->serial_port_used = new QSerialPort();
        }
        check_serail_eixsted();
        this ->serial_port_used ->setPortName(serial_port_name);
        if(this -> serial_port_used ->open(QIODevice::ReadWrite) == true)
        {
            /*opened successfully*/
            this -> serial_port_used ->setBaudRate(QSerialPort::Baud115200);
            this -> serial_port_used ->setDataBits(QSerialPort::Data8);
            this -> serial_port_used ->setStopBits(QSerialPort::OneStop);
            this -> serial_port_used ->setParity(QSerialPort::NoParity);
            this -> serial_port_used ->setFlowControl(QSerialPort::NoFlowControl);
            this-> current_status = comm_opened;
            qDebug()<<"comm opened sucessfully";
            /*send detailed inf about comm port to main collector*/
            //emit com_opened_signal(this ->current_device_num , serial_select->currentText());
            return true;
        }
        else
        {
             qDebug()<<"comm opened failed error:"<<serial_port_used->error()<<endl;
            /*record current status of comm */
            this-> current_status = comm_error;
            goto failed;
        }
        // serial_select ->currentText()
    }
failed:
    return false;
}
/*********************************************************************
 * @fn         void device::read_serial()
 *
 * @brief   slot function ,coresponded comm recive the data this function is triggerred
 *
 * @param   none
 *
 * @return   none
 */
size_t BlueGiga_controller::read_serial(char *buffer)
{
    qDebug()<<"BlueGiga_controller::read_serial";
    size_t data_rev_num = 0;
    if(serial_port_used->isOpen() ==false){
         if(BlueGiga_controller::open_serial() == false){
            return data_rev_num;
         }
    }
    if(serial_port_used->isOpen() ==true){
        QByteArray requestData;
        requestData = serial_port_used->readAll();
        data_rev_num = requestData.size();
        qDebug()<<"device lenth = "<<data_rev_num<<":"<<QString(buffer);
        if(requestData!= NULL){
            memcpy(buffer, requestData.data(), data_rev_num);
        }
        // serial_port_used->write(buffer , data_rev_num);

    }
    return data_rev_num;
}

void BlueGiga_controller::slot_read_serial()
{
    char buffer[512];
    size_t lenth = BlueGiga_controller::read_serial(buffer);
    read_message((unsigned char*)buffer, lenth);
    qDebug()<<"serial read data:"<<QString(buffer);
    //BlueGiga_controller::ble_connect_state_machine();
}

/*********************************************************************
 * @fn         void device::write_serial()
 *
 * @brief   write specific lenth of data to serial buffer
 *
 * @param   none
 *
 * @return   true: sucessfully
 *           false: failed
 */
int BlueGiga_controller::write_serial(char *p_buff, size_t lenth){
    if(serial_port_used->isOpen() == false){
         if(BlueGiga_controller::open_serial() == false){
            this-> current_status = comm_error;
            return false;
         }else{
             this-> current_status = comm_opened;
             return true;
         }
    }
    if(serial_port_used->isOpen() == true){
        if(serial_port_used->write((char*)(p_buff) , lenth) < lenth)
        {
            qDebug() << "serial data send error";
            return false;
        }
        serial_port_used ->flush();
    }else{
        qDebug() << "com opened failed";
        return false;
    }
    return true;
}

void BlueGiga_controller::sleep(unsigned int msec)
{
    QTime n=QTime::currentTime();

    QTime now;
    do{
      now=QTime::currentTime();
    }while (n.msecsTo(now)<=msec);

}

#define DEBUG
#define BLE_DEBUG_FOR_C(__x,...)do{\
   ble_printf(QString::asprintf(__x, ##__VA_ARGS__));\
}while(0)

void usage(char *exe)
{
    BLE_DEBUG_FOR_C("%s <COMx|list> <scan|address>\n", exe);
}

void change_state(states new_state)
{
#ifdef DEBUG
    BLE_DEBUG_FOR_C("DEBUG: State changed: %s --> %s\n", state_names[state], state_names[new_state]);
#endif
    state = new_state;
}


void print_bdaddr(bd_addr bdaddr)
{
    BLE_DEBUG_FOR_C("%02x:%02x:%02x:%02x:%02x:%02x",
            bdaddr.addr[5],
            bdaddr.addr[4],
            bdaddr.addr[3],
            bdaddr.addr[2],
            bdaddr.addr[1],
            bdaddr.addr[0]);
}

/**
 * Compare Bluetooth addresses
 *
 * @param first First address
 * @param second Second address
 * @return Zero if addresses are equal
 */
int cmp_bdaddr(bd_addr first, bd_addr second)
{
    unsigned int i;
    for (i = 0; i < sizeof(bd_addr); i++) {
        if (first.addr[i] != second.addr[i]) return 1;
    }
    return 0;
}

void enable_indications(uint8 connection_handle, uint16 client_configuration_handle)
{
    uint8 configuration[] = {0x02, 0x00}; // enable indications
    ble_cmd_attclient_attribute_write(connection_handle, thermometer_handle_configuration, 2, &configuration);
}

void print_raw_packet(struct ble_header *hdr, unsigned char *data)
{
    BLE_DEBUG_FOR_C("Incoming packet: ");
    unsigned int i;
    QString m("ble_header:");
    for (i = 0; i < sizeof(*hdr); i++) {
        m.append("0x");
        m.append(QString::number(((uint8*)hdr)[i],16));
        m.append(":");
    }
    ble_printf(m);
    QString t("data:");
    for (i = 0; i < hdr->lolen; i++) {
        t.append("0x");
        t.append(QString::number(((uint8*)data)[i],16));
        t.append(":");
    }
    ble_printf(t);
}


int read_message(unsigned char* data, size_t lenth)
{

    struct ble_header hdr;
    int r = 0;
    if (r < 0) {
        BLE_DEBUG_FOR_C("ERROR: Reading header failed. Error code:%d\n", r);
        return 1;
    }
    hdr = *((struct ble_header*)data);
    if (hdr.lolen) {
        //r = uart_rx(hdr.lolen, data, UART_TIMEOUT);
        if (r < 0) {
            BLE_DEBUG_FOR_C("ERROR: Reading data failed. Error code:%d\n", r);
            return 1;
        }
    }
    const struct ble_msg *msg = ble_get_msg_hdr(hdr);
#define DEBUG
#ifdef DEBUG
    print_raw_packet(&hdr, data+sizeof(hdr));
#endif
    if (!msg) {
        BLE_DEBUG_FOR_C("ERROR: Unknown message received\n");
        exit(1);
    }

    msg->handler(data + sizeof(hdr));

    return 0;
}
void ble_rsp_gap_connect_direct(const struct ble_msg_gap_connect_direct_rsp_t *msg)
{
     BLE_DEBUG_FOR_C("ble_rsp_gap_connect_direct result = %d handle =%d", msg->result, msg->connection_handle);
}
void ble_rsp_system_get_info(const struct ble_msg_system_get_info_rsp_t *msg)
{
    BLE_DEBUG_FOR_C("Build: %u, protocol_version: %u, hardware: ", msg->build, msg->protocol_version);
    switch (msg->hw) {
    case 0x01: BLE_DEBUG_FOR_C("BLE112"); break;
    case 0x02: BLE_DEBUG_FOR_C("BLED112"); break;
    default: BLE_DEBUG_FOR_C("Unknown");
    }
    BLE_DEBUG_FOR_C("\n");

    if (action == action_info) change_state(state_finish);
}

void ble_evt_gap_scan_response(const struct ble_msg_gap_scan_response_evt_t *msg)
{
    if (found_devices_count >= MAX_DEVICES) change_state(state_finish);

    int i;
    char *name = NULL;

    // Check if this device already found
    for (i = 0; i < found_devices_count; i++) {
        //if (!cmp_bdaddr(msg->sender, found_devices[i])) return;
    }
    found_devices_count++;
    memcpy(found_devices[i].addr, msg->sender.addr, sizeof(bd_addr));

    // Parse data
    for (i = 0; i < msg->data.len; ) {
        int8 len = msg->data.data[i++];
        if (!len) continue;
        if (i + len > msg->data.len) break; // not enough data
        uint8 type = msg->data.data[i++];
        switch (type) {
        case 0x09:
            name = (char*)malloc(len);
            memcpy(name, msg->data.data + i, len - 1);
            name[len - 1] = '\0';
        }

        i += len - 1;
    }

    print_bdaddr(msg->sender);
    BLE_DEBUG_FOR_C(" RSSI:%d", msg->rssi);

    BLE_DEBUG_FOR_C(" Name:");
    if (name) BLE_DEBUG_FOR_C("%s", name);
    else BLE_DEBUG_FOR_C("Unknown");
    BLE_DEBUG_FOR_C("\n");

    free(name);
}

void ble_evt_connection_status(const struct ble_msg_connection_status_evt_t *msg)
{
    // New connection
    if (msg->flags & connection_connected) {
        change_state(state_connected);
        BLE_DEBUG_FOR_C("Connected\n");

        // Handle for Temperature Measurement configuration already known
        if (thermometer_handle_configuration) {
            change_state(state_listening_measurements);
            enable_indications(msg->connection, thermometer_handle_configuration);
        }
        // Find primary services
        else {
            change_state(state_finding_services);
            BLE_DEBUG_FOR_C("Connection handle=%d\n", msg->connection);
            ble_cmd_attclient_read_by_group_type(msg->connection, FIRST_HANDLE, LAST_HANDLE, 2, primary_service_uuid);
        }
    }
}

void ble_evt_attclient_group_found(const struct ble_msg_attclient_group_found_evt_t *msg)
{

    if (msg->uuid.len == 0) return;
    uint16 uuid = (msg->uuid.data[1] << 8) | msg->uuid.data[0];
     BLE_DEBUG_FOR_C("attclient_group_found uuid= %x\n", uuid);
    // First thermometer service found
    if (state == state_finding_services && uuid == CLING_BLE_DEBUG_SERVICE_UUID && thermometer_handle_start == 0) {
        thermometer_handle_start = msg->start;
        thermometer_handle_end = msg->end;
    }
}

void ble_evt_attclient_procedure_completed(const struct ble_msg_attclient_procedure_completed_evt_t *msg)
{
    if (state == state_finding_services) {
        // Thermometer service not found
        if (thermometer_handle_start == 0) {
            BLE_DEBUG_FOR_C("No Health Thermometer service found\n");
            change_state(state_finish);
        }
        // Find thermometer service attributes
        else {
            change_state(state_finding_attributes);
            BLE_DEBUG_FOR_C("thermometer_handle_start = %d, thermometer_handle_end = %d",thermometer_handle_start,thermometer_handle_end);
            ble_cmd_attclient_find_information(msg->connection, thermometer_handle_start, thermometer_handle_end);
        }
    }
    else if (state == state_finding_attributes) {
        // Client characteristic configuration not found
        if (thermometer_handle_configuration == 0) {
            BLE_DEBUG_FOR_C("No Client Characteristic Configuration found for Health Thermometer service\n");
            change_state(state_finish);
        }
        // Enable temperature notifications
        else {
            change_state(state_listening_measurements);
            enable_indications(msg->connection, thermometer_handle_configuration);
        }
    }
}

void ble_evt_attclient_find_information_found(const struct ble_msg_attclient_find_information_found_evt_t *msg)
{
    if (msg->uuid.len == 2) {
        uint16 uuid = (msg->uuid.data[1] << 8) | msg->uuid.data[0];
        BLE_DEBUG_FOR_C("Client Characteristic uuid = %x\n",uuid);
        if (uuid == CLING_BLE_DEBUG_TX_UUID) {
            BLE_DEBUG_FOR_C(" Client TX Characteristic uuid found");
            thermometer_handle_measurement = msg->chrhandle;
        }
        else if (uuid == CLING_BLE_DEBUG_RX_UUID) {
            BLE_DEBUG_FOR_C(" Client RX Characteristic uuid found");
            thermometer_handle_configuration = msg->chrhandle;
        }
    }
}

#define THERMOMETER_FLAGS_FAHRENHEIT 0x1
void ble_evt_attclient_attribute_value(const struct ble_msg_attclient_attribute_value_evt_t *msg)
{
    if (msg->value.len < 5) {
        BLE_DEBUG_FOR_C("Not enough fields in Temperature Measurement value");
        change_state(state_finish);
    }

    uint8 flags = msg->value.data[0];
    int8 exponent = msg->value.data[4];
    int mantissa = (msg->value.data[3] << 16) | (msg->value.data[2] << 8) | msg->value.data[1];

    float value =0;//= mantissa * pow(10, exponent);
    if (exponent >= 0)
        exponent = 0;
    else
        exponent = abs(exponent);
     BLE_DEBUG_FOR_C("Temperature: %.*f ", exponent, value);

    if (flags & THERMOMETER_FLAGS_FAHRENHEIT)
        BLE_DEBUG_FOR_C("F");
    else
        BLE_DEBUG_FOR_C("C");
    BLE_DEBUG_FOR_C("\n");
}

void ble_evt_connection_disconnected(const struct ble_msg_connection_disconnected_evt_t *msg)
{
    change_state(state_disconnected);
    BLE_DEBUG_FOR_C("Connection terminated, trying to reconnect\n");
    change_state(state_connecting);
    ble_cmd_gap_connect_direct(&connect_addr, gap_address_type_public, 40, 60, 100,0);
}


void BlueGiga_controller::ble_tx(uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{  
    if ((BlueGiga_controller::write_serial((char*)data1, len1) == false) || (BlueGiga_controller::write_serial((char*)data2, len2) == false)) {
        BLE_DEBUG_FOR_C("ERROR: Writing to serial port failed\n");
        //exit(1);
    }
}

// wrapper function for ble transmitting
extern "C" void call_Lib_CPPFunction_ble_tx(BlueGiga_controller* p,uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{
    p->ble_tx(len1, data1, len2, data2);
}

BlueGiga_controller *BlueGiga_controller::get_instance(){
    if(BlueGiga_controller::p_instance != NULL){
        return BlueGiga_controller::p_instance;
    }
    return NULL;
}

void output(uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{
    call_Lib_CPPFunction_ble_tx(BlueGiga_controller::get_instance(), len1, data1, len2, data2);
}

int BlueGiga_controller::set_ble_control_phy_output(){
     bglib_output = &output;
     return true;
}

int BlueGiga_controller::ble_connect_state_machine(){
    action = action_scan;
    bglib_output = &output;
    // Reset dongle to get it into known state
    ble_cmd_system_reset(0);
    sleep(500);
    serial_port_used->close();
    this->current_status = comm_closed;
    this->open_serial();
    // Execute action
    if (action == action_scan) {
        ble_cmd_gap_discover(gap_discover_observation);
    }
    else if (action == action_info) {
        ble_cmd_system_get_info();
    }
    else if (action == action_connect) {
        ble_debug("Trying to connect\n");
        change_state(state_connecting);
        connect_addr ={0xfa,0xce,0x88,0x16,0xe2,0x55};
        ble_cmd_gap_connect_direct(&connect_addr, gap_address_type_public, 40, 60, 100,0);
    }
    return 0;
}



uint8 charToData(const char ch)
{
 switch(ch)
 {
 case '0': return 0;
 case '1': return 1;
 case '2': return 2;
 case '3': return 3;
 case '4': return 4;
 case '5': return 5;
 case '6': return 6;
 case '7': return 7;
 case '8': return 8;
 case '9': return 9;
 case 'a':
 case 'A': return 10;
 case 'b':
 case 'B': return 11;
 case 'c':
 case 'C': return 12;
 case 'd':
 case 'D': return 13;
 case 'e':
 case 'E': return 14;
 case 'f':
 case 'F': return 15;
 }
 return 0;
}


bool BlueGiga_controller::str_to_mac(const char * szMac, uint8* pMac)
{
#define BLE_MAC_LENTH 6
     const char * pTemp = szMac;
     for (int i = 0;i < BLE_MAC_LENTH;++i)
     {
          //qDebug()<<"original pmac："<<i<<"member="<<pTemp[0]<<pTemp[1];
          pMac[BLE_MAC_LENTH-i-1] =  charToData(*pTemp++) * 16;
          pMac[BLE_MAC_LENTH-i-1] += charToData(*pTemp++);
          pTemp++;
          //qDebug()<<"str to mac pmac："<<i<<"member="<<pMac[i];
     }
    return true;
}
bool BlueGiga_controller::ble_debug(QString a){
    ble_ui->textEdit_ble_log->append(a);
    return true;
}

// wrapper function for ble transmitting
extern "C" void call_Lib_CPPFunction_ble_ble_debug(BlueGiga_controller* p, QString a)
{
    p->ble_debug(a);
}

void ble_printf(QString t){
    qDebug()<<t;
    call_Lib_CPPFunction_ble_ble_debug(BlueGiga_controller::get_instance(), t);
}

void reset_ble_state_machine(){
           thermometer_handle_start = 0;
           thermometer_handle_end = 0;
           thermometer_handle_measurement = 0;
           thermometer_handle_configuration = 0;
           change_state(state_disconnected);
}

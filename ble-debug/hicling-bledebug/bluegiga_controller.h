#ifndef BLUEGIGA_CONTROLLER_H
#define BLUEGIGA_CONTROLLER_H
#include"stdio.h"
#include <QString>
#include <QSerialPort>
#include <QDebug>
#include <QObject>
#include <QDialog>
#include "./bglib/cmd_def.h"
#include "ui_ble_conn_dialog.h"
#include <QCloseEvent>
#include <QSerialPortInfo>
#include <QTime>
namespace Ui {
class BlueGiga_controller;
}
extern "C"{
int read_message(unsigned char* data, size_t lenth);
void ble_printf(QString);
void reset_ble_state_machine();
}
class BlueGiga_controller : public QDialog
{
    Q_OBJECT
public:
    static BlueGiga_controller* get_instance(int com_num);
    static BlueGiga_controller* get_instance();
    void ble_tx(uint8 len1, uint8 *data1, uint16 len2, uint8 *data2);
    int ble_connect_state_machine();
    bool ble_debug(QString);
public slots:
    void serial_error_slot(QSerialPort::SerialPortError error)
    {
        qDebug()<< "serial error code:" << error;
    }
    void slot_read_serial();

private slots:
    void push_button_ble_connect_slot();
    void push_button_ble_disconnect_slot();
    void push_button_ble_add_mac_slot();
    void push_button_log_clear_slot();

private:
    enum dev_state{
        comm_unkhnown=0,
        comm_closed,
        comm_opened ,
        comm_error,
    };
    Ui_ble_conn_dialog *ble_ui;
    enum dev_state current_status;
    QString         serial_port_name;
    QSerialPort    *serial_port_used;
    static BlueGiga_controller *p_instance;
    explicit BlueGiga_controller(QWidget *parent = 0, QString serial_port = "COM1");
    ~BlueGiga_controller();

    bool open_serial();
    size_t read_serial(char *buffer);
    int write_serial(char *p_buff, size_t lenth);


    void sleep(unsigned int msec);
    void closeEvent(QCloseEvent *event);
    int set_ble_control_phy_output();
    bool close_serial();
    bool check_serail_eixsted();
    int macstr_2_macum(unsigned char *macstr, unsigned char *macAddrNum);
    bool str_to_mac(const char *szMac, uint8 *pMac);

};

#endif // BLUEGIGA_CONTROLLER_H

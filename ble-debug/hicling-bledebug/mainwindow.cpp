#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include <QVBoxLayout>
#include "bluegiga_controller.h"
BlueGiga_controller *t;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    group_box_comm_type(NULL),
    checkbox_ble(NULL),
    radio_button_i2c(NULL),
    radio_button_uart(NULL),
    tab_parameters(NULL),
    text_edit_debug_message(NULL),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qt::WindowFlags flags=this->windowFlags();
    flags |=Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint|Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    ui->centralWidget->setLayout(ui->gridLayout);
    ui->centralWidget->setAutoFillBackground(true);
    MainWindow::initiate_comm_type_control_borad();
    MainWindow::initiate_parameter_control_board();
    MainWindow::initiate_debug_comm_send_control_board();


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}



/*start debug push button slot*/
void MainWindow::push_button_start_debug_slot(){
 qDebug()<<"push_button_start_debug_slot";

}
void MainWindow::push_button_stop_debug_slot(){
 qDebug()<<"push_button_stop_debug_slot";

}

void MainWindow::initiate_parameter_control_board(){

 #define PARAMATER_FIRST_PAGE_NUMBERS 3
    const QString str[PARAMATER_FIRST_PAGE_NUMBERS] = {
        "Enable sleep",
        "Sleep delay",
        "CPU MODE"
    };
    /*debug control panel*/
    QPushButton *push_button_start_debug = new QPushButton(tr("start debug"));
    QPushButton *push_button_stop_debug  = new QPushButton(tr("stop debug"));
    connect(push_button_start_debug , SIGNAL(clicked()) , this , SLOT(push_button_start_debug_slot()));
    connect(push_button_stop_debug , SIGNAL(clicked()) , this , SLOT(push_button_stop_debug_slot()));
    QLineEdit   *line_edit_parameter[PARAMATER_FIRST_PAGE_NUMBERS];
    QGridLayout *t =  new QGridLayout();
    int i = 0;
    for(i = 0; i < PARAMATER_FIRST_PAGE_NUMBERS; i++){
        QLabel *l = new QLabel(str[i]);
        line_edit_parameter[i] = new QLineEdit();
        t->addWidget(l, i, 1);
        t->addWidget(line_edit_parameter[i], i, 3);
       // t->addWidget(new );
    }
    t->addWidget(push_button_start_debug, i++, 1);
   // t->addStretch();
    t->addWidget(push_button_stop_debug,  i++, 1);
    QWidget * page_system_parameter = new QWidget();
    page_system_parameter->setLayout(t);
    this->tab_parameters = new QTabWidget();
    this->tab_parameters->addTab(page_system_parameter,"system parameters");
    QBoxLayout *box_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    box_layout->addWidget(this->tab_parameters);
    ui->groupBox_parameter->setLayout(box_layout);

}



void MainWindow::push_button_cmd_clear_slot(){

    qDebug()<<"push_button_cmd_clear_slot";

}

void MainWindow::push_button_debug_clear_slot(){
    qDebug()<<"push_button_debug_clear_slot";

}
void MainWindow::push_button_debug_save_slot(){
    qDebug()<<"push_button_debug_save_slot";
}
void MainWindow::check_box_save_log_slot(bool checked){
    qDebug()<<"check_box_save_log_slot";

}


void MainWindow::initiate_debug_comm_send_control_board()
{

    QPushButton *push_button_cmd_clear = new QPushButton(tr("cmd clear"));
    QPushButton *push_button_debug_clear = new QPushButton(tr("debug clear"));
    QPushButton *push_button_debug_save = new QPushButton(tr("save"));
    QCheckBox   *check_box_save_log = new QCheckBox("save log");
    QLineEdit   *line_edit_debug_cmd_send  = new QLineEdit();
    QPushButton *push_button_debug_send = new QPushButton(tr("send"));
    this->text_edit_debug_message = new QTextEdit();

    /*connect related signal to slot*/
    connect(push_button_cmd_clear , SIGNAL(clicked()) , this , SLOT(push_button_cmd_clear_slot()));
    connect(push_button_debug_clear , SIGNAL(clicked()) , this , SLOT(push_button_debug_clear_slot()));
    connect(push_button_debug_save , SIGNAL(clicked()) , this , SLOT(push_button_debug_save_slot()));
    connect(check_box_save_log , SIGNAL(clicked(bool)) , this , SLOT(check_box_save_log_slot(bool)));

    QHBoxLayout *h_1 = new QHBoxLayout();
    h_1->addWidget(push_button_cmd_clear,0 ,Qt::AlignLeft);
    h_1->addStretch(1);
    h_1->addWidget(push_button_debug_clear);
    h_1->addWidget(push_button_debug_save);
    h_1->addWidget(check_box_save_log);

    QHBoxLayout *h_2 = new QHBoxLayout();
    h_2->addWidget(line_edit_debug_cmd_send);
    h_2->addWidget(push_button_debug_send);
    qDebug() << "This is debug";
    QBoxLayout *box_layout = new QBoxLayout(QBoxLayout::LeftToRight);
    box_layout->addWidget(text_edit_debug_message);
    text_edit_debug_message->setReadOnly(true);
    /*add to second layout*/
    QVBoxLayout *v_1 = new QVBoxLayout();
    v_1->addLayout(h_1);
    v_1->addLayout(h_2);
    v_1->addLayout(box_layout);
    /*add outest layout*/
    ui->groupBox_console->setLayout(v_1);
}

void MainWindow::radio_button_i2c_slot(bool checked)
{
    qDebug()<<"radio_button_i2c_slot";
}
void MainWindow::radio_button_uart_slot(bool checked)
{
    qDebug()<<"radio_button_uart_slot";
}

void MainWindow::checkbox_ble_slot(bool checked)
{
    if(checked == true){
        qDebug()<<"radio_button_checkbox_ble_slot";
        int com_num = ui->spinBox_com_num->value();
        t = BlueGiga_controller::get_instance(com_num);
        this->checkbox_ble->setCheckState(Qt::Unchecked);
    }
}
void MainWindow::initiate_comm_type_control_borad()
{
    /*set up communication type seleted forum*/
    this->group_box_comm_type = ui->groupBox_comm_type;
    QHBoxLayout *comm_type_h_layout =  new QHBoxLayout;
    this->radio_button_i2c =  new QRadioButton("I2C");
    this->radio_button_uart =  new QRadioButton("COMM");
    this->checkbox_ble  = new QCheckBox("ble");

    connect( this->radio_button_i2c , SIGNAL(clicked(bool)) , this , SLOT(radio_button_i2c_slot(bool)));
    connect( this->radio_button_uart , SIGNAL(clicked(bool)) , this , SLOT(radio_button_uart_slot(bool)));
    connect(this->checkbox_ble , SIGNAL(clicked(bool)) , this , SLOT(checkbox_ble_slot(bool)));

    comm_type_h_layout->addWidget(radio_button_i2c);
    comm_type_h_layout->addWidget(radio_button_uart);
    comm_type_h_layout->addWidget(checkbox_ble);
    this->group_box_comm_type->setLayout(comm_type_h_layout);
    /*end communication forum configure  */
}


#if 1
void MainWindow::on_push_button_open_close_clicked()
{
    qDebug() << "Qt main window open slot function";
    t->ble_connect_state_machine();
}
#endif

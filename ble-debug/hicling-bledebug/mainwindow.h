#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTabWidget>
#include <QTextBrowser>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_push_button_open_close_clicked();

    void push_button_start_debug_slot();
    void push_button_stop_debug_slot();
    void push_button_cmd_clear_slot();
    void push_button_debug_clear_slot();
    void push_button_debug_save_slot();
    void check_box_save_log_slot(bool checked);
    void radio_button_i2c_slot(bool checked);
    void radio_button_uart_slot(bool checked);
    void checkbox_ble_slot(bool checked);
private:
    void initiate_comm_type_control_borad();
    void initiate_parameter_control_board();
    void initiate_debug_comm_send_control_board();
    Ui::MainWindow *ui;
    QGroupBox *group_box_comm_type;
    QCheckBox *checkbox_ble;
    QRadioButton *radio_button_i2c;
    QRadioButton *radio_button_uart;
    QTabWidget *tab_parameters;
    QTextEdit *text_edit_debug_message;

};

#endif // MAINWINDOW_H

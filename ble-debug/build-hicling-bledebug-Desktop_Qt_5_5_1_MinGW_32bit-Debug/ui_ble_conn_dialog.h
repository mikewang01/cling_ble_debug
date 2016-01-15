/********************************************************************************
** Form generated from reading UI file 'ble_conn_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLE_CONN_DIALOG_H
#define UI_BLE_CONN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ble_conn_dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_ble_connect;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_ble_disconnect;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_ble_log_clear;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QComboBox *comboBox_mac_select;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_mac_addr;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_addmac;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_ble_log;

    void setupUi(QDialog *ble_conn_dialog)
    {
        if (ble_conn_dialog->objectName().isEmpty())
            ble_conn_dialog->setObjectName(QStringLiteral("ble_conn_dialog"));
        ble_conn_dialog->resize(403, 300);
        ble_conn_dialog->setSizeGripEnabled(false);
        gridLayoutWidget = new QWidget(ble_conn_dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 20, 321, 309));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButton_ble_connect = new QPushButton(gridLayoutWidget);
        pushButton_ble_connect->setObjectName(QStringLiteral("pushButton_ble_connect"));

        horizontalLayout_5->addWidget(pushButton_ble_connect);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        pushButton_ble_disconnect = new QPushButton(gridLayoutWidget);
        pushButton_ble_disconnect->setObjectName(QStringLiteral("pushButton_ble_disconnect"));

        horizontalLayout_6->addWidget(pushButton_ble_disconnect);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        pushButton_ble_log_clear = new QPushButton(gridLayoutWidget);
        pushButton_ble_log_clear->setObjectName(QStringLiteral("pushButton_ble_log_clear"));

        horizontalLayout_7->addWidget(pushButton_ble_log_clear);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        comboBox_mac_select = new QComboBox(gridLayoutWidget);
        comboBox_mac_select->setObjectName(QStringLiteral("comboBox_mac_select"));
        sizePolicy.setHeightForWidth(comboBox_mac_select->sizePolicy().hasHeightForWidth());
        comboBox_mac_select->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(comboBox_mac_select);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        horizontalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_2->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_mac_addr = new QLineEdit(gridLayoutWidget);
        lineEdit_mac_addr->setObjectName(QStringLiteral("lineEdit_mac_addr"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_mac_addr->sizePolicy().hasHeightForWidth());
        lineEdit_mac_addr->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_mac_addr);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        pushButton_addmac = new QPushButton(gridLayoutWidget);
        pushButton_addmac->setObjectName(QStringLiteral("pushButton_addmac"));

        horizontalLayout_3->addWidget(pushButton_addmac);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        textEdit_ble_log = new QTextEdit(gridLayoutWidget);
        textEdit_ble_log->setObjectName(QStringLiteral("textEdit_ble_log"));
        sizePolicy.setHeightForWidth(textEdit_ble_log->sizePolicy().hasHeightForWidth());
        textEdit_ble_log->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit_ble_log);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ble_conn_dialog);

        QMetaObject::connectSlotsByName(ble_conn_dialog);
    } // setupUi

    void retranslateUi(QDialog *ble_conn_dialog)
    {
        ble_conn_dialog->setWindowTitle(QApplication::translate("ble_conn_dialog", "Dialog", 0));
        pushButton_ble_connect->setText(QApplication::translate("ble_conn_dialog", "connect", 0));
        pushButton_ble_disconnect->setText(QApplication::translate("ble_conn_dialog", "disconnect", 0));
        pushButton_ble_log_clear->setText(QApplication::translate("ble_conn_dialog", "clear", 0));
        label->setText(QApplication::translate("ble_conn_dialog", "MAC", 0));
        comboBox_mac_select->clear();
        comboBox_mac_select->insertItems(0, QStringList()
         << QApplication::translate("ble_conn_dialog", "01:02:03:04:05:06", 0)
        );
        pushButton_addmac->setText(QApplication::translate("ble_conn_dialog", "add mac", 0));
    } // retranslateUi

};

namespace Ui {
    class ble_conn_dialog: public Ui_ble_conn_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_CONN_DIALOG_H

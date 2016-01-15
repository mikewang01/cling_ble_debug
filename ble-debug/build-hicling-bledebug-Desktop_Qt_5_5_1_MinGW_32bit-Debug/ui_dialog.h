/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_ble_connect;
    QPushButton *pushButton_ble_disconnect;
    QPushButton *pushButton_ble_log_clear;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_mac_select;
    QLineEdit *lineEdit_mac_addr;
    QPushButton *pushButton_addmac;
    QTextEdit *textEdit_ble_log;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 260, 307));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_ble_connect = new QPushButton(gridLayoutWidget);
        pushButton_ble_connect->setObjectName(QStringLiteral("pushButton_ble_connect"));

        verticalLayout_3->addWidget(pushButton_ble_connect);

        pushButton_ble_disconnect = new QPushButton(gridLayoutWidget);
        pushButton_ble_disconnect->setObjectName(QStringLiteral("pushButton_ble_disconnect"));

        verticalLayout_3->addWidget(pushButton_ble_disconnect);

        pushButton_ble_log_clear = new QPushButton(gridLayoutWidget);
        pushButton_ble_log_clear->setObjectName(QStringLiteral("pushButton_ble_log_clear"));

        verticalLayout_3->addWidget(pushButton_ble_log_clear);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
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

        horizontalLayout_2->addWidget(comboBox_mac_select);

        horizontalLayout_2->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit_mac_addr = new QLineEdit(gridLayoutWidget);
        lineEdit_mac_addr->setObjectName(QStringLiteral("lineEdit_mac_addr"));

        verticalLayout_2->addWidget(lineEdit_mac_addr);

        pushButton_addmac = new QPushButton(gridLayoutWidget);
        pushButton_addmac->setObjectName(QStringLiteral("pushButton_addmac"));

        verticalLayout_2->addWidget(pushButton_addmac);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);

        textEdit_ble_log = new QTextEdit(gridLayoutWidget);
        textEdit_ble_log->setObjectName(QStringLiteral("textEdit_ble_log"));
        sizePolicy.setHeightForWidth(textEdit_ble_log->sizePolicy().hasHeightForWidth());
        textEdit_ble_log->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textEdit_ble_log);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_ble_connect->setText(QApplication::translate("Dialog", "connect", 0));
        pushButton_ble_disconnect->setText(QApplication::translate("Dialog", "disconnect", 0));
        pushButton_ble_log_clear->setText(QApplication::translate("Dialog", "clear", 0));
        label->setText(QApplication::translate("Dialog", "MAC", 0));
        pushButton_addmac->setText(QApplication::translate("Dialog", "add mac", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_dis;
    QVBoxLayout *verticalLayout_comm_select;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *push_button_open_close;
    QSpacerItem *horizontalSpacer;
    QLabel *label_dev_status;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spinBox_com_num;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_comm_type;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_parameter;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_console;
    QVBoxLayout *verticalLayout_dev_config;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *tab_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1080, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(1080, 720));
        MainWindow->setSizeIncrement(QSize(20, 20));
        MainWindow->setWindowTitle(QStringLiteral("MainWindow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-10, -10, 781, 441));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(1, 20, 1, 1);
        verticalLayout_dis = new QVBoxLayout();
        verticalLayout_dis->setSpacing(4);
        verticalLayout_dis->setObjectName(QStringLiteral("verticalLayout_dis"));
        verticalLayout_dis->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_comm_select = new QVBoxLayout();
        verticalLayout_comm_select->setSpacing(6);
        verticalLayout_comm_select->setObjectName(QStringLiteral("verticalLayout_comm_select"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        push_button_open_close = new QPushButton(gridLayoutWidget);
        push_button_open_close->setObjectName(QStringLiteral("push_button_open_close"));

        horizontalLayout_2->addWidget(push_button_open_close);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_dev_status = new QLabel(gridLayoutWidget);
        label_dev_status->setObjectName(QStringLiteral("label_dev_status"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_dev_status->sizePolicy().hasHeightForWidth());
        label_dev_status->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_dev_status);


        verticalLayout_comm_select->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spinBox_com_num = new QSpinBox(gridLayoutWidget);
        spinBox_com_num->setObjectName(QStringLiteral("spinBox_com_num"));

        horizontalLayout_5->addWidget(spinBox_com_num);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_comm_select->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_comm_type = new QGroupBox(gridLayoutWidget);
        groupBox_comm_type->setObjectName(QStringLiteral("groupBox_comm_type"));

        horizontalLayout->addWidget(groupBox_comm_type);


        verticalLayout_comm_select->addLayout(horizontalLayout);


        verticalLayout_dis->addLayout(verticalLayout_comm_select);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_dis->addItem(verticalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_parameter = new QGroupBox(gridLayoutWidget);
        groupBox_parameter->setObjectName(QStringLiteral("groupBox_parameter"));

        verticalLayout_6->addWidget(groupBox_parameter);


        verticalLayout_dis->addLayout(verticalLayout_6);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_dis->addItem(verticalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_console = new QGroupBox(gridLayoutWidget);
        groupBox_console->setObjectName(QStringLiteral("groupBox_console"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(groupBox_console->sizePolicy().hasHeightForWidth());
        groupBox_console->setSizePolicy(sizePolicy2);

        verticalLayout_5->addWidget(groupBox_console);


        verticalLayout_dis->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_dis, 0, 1, 1, 1);

        verticalLayout_dev_config = new QVBoxLayout();
        verticalLayout_dev_config->setSpacing(6);
        verticalLayout_dev_config->setObjectName(QStringLiteral("verticalLayout_dev_config"));
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(12);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_dev_config->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout_dev_config, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        push_button_open_close->setText(QApplication::translate("MainWindow", "Open", 0));
        label_dev_status->setText(QApplication::translate("MainWindow", "port closed", 0));
        label->setText(QApplication::translate("MainWindow", "com number", 0));
        groupBox_comm_type->setTitle(QApplication::translate("MainWindow", "communication type", 0));
        groupBox_parameter->setTitle(QApplication::translate("MainWindow", "parameters", 0));
        groupBox_console->setTitle(QApplication::translate("MainWindow", "console", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

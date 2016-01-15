#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T10:22:03
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hicling-bledebug
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bglib/cmd_def.c \
    bglib/commands.c \
    bluegiga_controller.cpp

HEADERS  += mainwindow.h \
    bglib/apitypes.h \
    bglib/cmd_def.h \
    bluegiga_controller.h \
    bluegiga.h \
    ble_dialog.h

FORMS    += \
    ble_conn_dialog.ui \
    mainwindow.ui

DISTFILES +=

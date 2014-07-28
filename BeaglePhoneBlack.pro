#-------------------------------------------------
#
# Project created by QtCreator 2014-07-25T09:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qesp_linux_udev
include(Serial/qextserialport/src/qextserialport.pri)

TARGET = BeaglePhoneBlack
    target.files = BeaglePhoneBlack
    target.path = /home/BeaglePhoneBlack

INSTALLS += target
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialer.cpp \
    homepage.cpp \
    textthread.cpp \
    texthome.cpp \
    power.cpp \
    serial.cpp

HEADERS  += mainwindow.h \
    dialer.h \
    homepage.h \
    textthread.h \
    texthome.h \
    power.h \
    serial.h

FORMS    += mainwindow.ui \
    dialer.ui \
    homepage.ui \
    textthread.ui \
    texthome.ui \
    power.ui

RESOURCES = \
    sources.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2014-07-25T15:03:51
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QflotMPDcliente
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mpdcomandos.cpp

HEADERS  += mainwindow.h \
    mpdcomandos.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2022-06-30T17:46:01
#
#-------------------------------------------------

QT += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeOftheSky
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

include( $$PWD/JQLibrary/JQLibrary.pri )
include( $$PWD/JQLibrary/JQQRCodeReader.pri )

SOURCES += \
        main.cpp \
        login.cpp \
    mainwindow.cpp

HEADERS += \
        login.h \
    mainwindow.h

RESOURCES += \
    res.qrc

FORMS += \
    mainwindow.ui

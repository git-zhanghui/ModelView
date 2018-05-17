#-------------------------------------------------
#
# Project created by QtCreator 2018-05-17T23:28:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModelView
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/../bin

MOC_DIR = $$PWD/../tmp/moc
OBJECTS_DIR = $$PWD/../tmp/obj
RCC_DIR = $$PWD/../tmp/rcc
UI_DIR = $$PWD/../tmp/form

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    reimplementedtablemodel.cpp

HEADERS += \
        mainwindow.h \
    reimplementedtablemodel.h

FORMS += \
        mainwindow.ui

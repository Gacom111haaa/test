#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T21:21:55
#
#-------------------------------------------------

QT       += core gui
QT += xml
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qgis_00
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    map.cpp \
    citem.cpp \
    window.cpp \
    mainwindow1.cpp \
    mapcanvas.cpp \
    cserialport.cpp \
    cgpslog.cpp \
    cgpslogwidget.cpp \
    clogfile.cpp

HEADERS  += mainwindow.h \
    map.h \
    citem.h \
    window.h \
    mainwindow1.h \
    mapcanvas.h \
    cserialport.h \
    cgpslog.h \
    cgpslogwidget.h \
    clogfile.h

FORMS    += mainwindow.ui \
    mainwindow1.ui \
    cgpslog.ui \
    test.ui

LIBS += -L/usr/local/lib/ -lqgis_core -lqgis_gui
INCLUDEPATH += /usr/include/qgis
DEFINES += GUI_EXPORT= CORE_EXPORT=

LIBS += -L/usr/local/lib -lwiringPi
INCLUDEPATH += /usr/local/include


#unix:HEADERS  += wiringSerial.h
#unix:LIBS     += -lwiringPi

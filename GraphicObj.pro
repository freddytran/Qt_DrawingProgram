#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T09:32:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicObj
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    rectangle.cpp \
    circle.cpp \
    graphicsobject.cpp \
    tools.cpp \
    graphicsobjectsmap.cpp \
    graphicsscene.cpp \
    colorbutton.cpp \
    drawingtoolselector.cpp \
    colorselector.cpp \
    objectoptions.cpp \
    polygon.cpp

HEADERS += \
        mainwindow.h \
    rectangle.h \
    circle.h \
    graphicsobject.h \
    tools.h \
    graphicsobjectsmap.h \
    graphicsscene.h \
    colorbutton.h \
    drawingtoolselector.h \
    colorselector.h \
    objectoptions.h \
    polygon.h

FORMS += \
        mainwindow.ui \
    drawingtoolselector.ui \
    colorselector.ui \
    objectoptions.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    Icons/polygon.png

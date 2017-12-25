#-------------------------------------------------
#
# Project created by QtCreator 2017-12-21T13:43:16
#
#-------------------------------------------------

QT       += core gui opengl
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Panic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    map/cell.cpp \
    map/floor.cpp \
    map/floorimage.cpp \
    human/human.cpp \
    map/map.cpp \
    graph/simulatorwidget.cpp \
    human/health.cpp \
    mapgen/mapgenerator.cpp \
    mapgen/mapgeneratorcafe.cpp \
    mapgen/humanlistgenerator.cpp \
    mapgen/imagepositions.cpp \
    map/barrier.cpp

HEADERS  += mainwindow.h \
    map/cell.h \
    common/types.h \
    map/floor.h \
    map/floorimage.h \
    human/human.h \
    map/map.h \
    graph/simulatorwidget.h \
    human/health.h \
    mapgen/mapgenerator.h \
    mapgen/mapgeneratorcafe.h \
    mapgen/humanlistgenerator.h \
    mapgen/imagepositions.h \
    map/barrier.h

FORMS    += mainwindow.ui

target.path = $$OUT_PWD
target.files = $$PWD/install/maps/
INSTALLS += target

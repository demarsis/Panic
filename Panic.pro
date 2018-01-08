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
    map/barrier.cpp \
    map/exit.cpp \
    map/mappositions.cpp \
    mapgen/imagebarriers.cpp \
    map/mapbarriers.cpp \
    common/consolelogger.cpp \
    mapgen/floordescriptor.cpp \
    mapgen/floorgenerator.cpp \
    mapgen/allmapgenerators.cpp \
    widgets/buttonstartstop.cpp \
    simulation/stopwatch.cpp \
    widgets/stopwatchlabel.cpp \
    widgets/buttonreset.cpp \
    simulation/simulator.cpp \
    human/humaninfluence.cpp \
    human/gender.cpp \
    human/age.cpp \
    graph/humanicontextures.cpp \
    probability/probability.cpp \
    mapgen/mapcharacteristics.cpp \
    simulation/vector.cpp \
    simulation/directions.cpp \
    map/cellmatrix.cpp \
    simulation/penaltywaybuilder.cpp \
    simulation/humanvector.cpp \
    mapgen/mapgeneratortestfindexit.cpp \
    widgets/combosimulationspeed.cpp \
    map/mappushes.cpp \
    map/gradient.cpp \
    map/pushesimage.cpp \
    report/report.cpp \
    report/simulationreport.cpp

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
    map/barrier.h \
    map/exit.h \
    map/mappositions.h \
    mapgen/imagebarriers.h \
    map/mapbarriers.h \
    common/defines.h \
    common/consolelogger.h \
    mapgen/floordescriptor.h \
    mapgen/floorgenerator.h \
    mapgen/allmapgenerators.h \
    widgets/buttonstartstop.h \
    simulation/stopwatch.h \
    widgets/stopwatchlabel.h \
    widgets/buttonreset.h \
    simulation/simulator.h \
    human/humaninfluence.h \
    human/gender.h \
    human/age.h \
    graph/humanicontextures.h \
    probability/probability.h \
    probability/probabilityrelation.h \
    mapgen/mapcharacteristics.h \
    simulation/vector.h \
    simulation/directions.h \
    map/cellmatrix.h \
    simulation/penaltywaybuilder.h \
    simulation/humanvector.h \
    mapgen/mapgeneratortestfindexit.h \
    widgets/combosimulationspeed.h \
    map/mappushes.h \
    map/gradient.h \
    map/pushesimage.h \
    report/report.h \
    report/simulationreport.h

FORMS    += mainwindow.ui

# install maps
install_maps.path = $$OUT_PWD
install_maps.files = $$PWD/maps/
INSTALLS += install_maps

# install textures
install_textures.path = $$OUT_PWD
install_textures.files = $$PWD/textures/
INSTALLS += install_textures

RESOURCES += \
    icons/icons.qrc

#set application icon
RC_ICONS += icons/crowd.ico

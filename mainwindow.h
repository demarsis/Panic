#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common/consolelogger.h"
#include "mapgen/allmapgenerators.h"
#include "map/floor.h"
#include "map/map.h"
#include "simulation/simulator.h"
#include "mapgen/mapcharacteristics.h"
#include "probability/probabilityrelation.h"
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MapPtr currentGeneratedMap;
    SimulatorPtr simulator;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadAllAvialableMaps();

    // create/reset simulation based on generated map
    void newSimulation();

    // get map parameters
    MapCharacteristics createMapCharacteristicsFromGUI();

    void loadCurrentSimulatorIntoGUI();
    void toggleFloor(FloorPtr floor);


private slots:
    void on_pushButtonGenerateMap_clicked();
    void on_listWidgetFloor_currentRowChanged(int currentRow);
    void calledStartedSimulation();
    void calledPausedSimulation();
    void calledResetSimulation();
    void updateManWomenPercents();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

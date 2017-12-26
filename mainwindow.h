#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common/consolelogger.h"
#include "mapgen/allmapgenerators.h"
#include "map/floor.h"
#include "map/map.h"
#include <QVariant>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    MapPtr currentMap;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadMapPtrs();
    void loadMap(MapGeneratorPtr mapPtr);
    void toggleFloor(FloorPtr floor);

private slots:
    void on_pushButtonLoadMap_clicked();
    void on_listWidgetFloor_currentRowChanged(int currentRow);
    void calledStartedSimulation();
    void calledPausedSimulation();
    void calledResetSimulation();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

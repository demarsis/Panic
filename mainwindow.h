#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void loadFloor(FloorPtr floor);

private slots:

    void on_pushButtonLoadMap_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

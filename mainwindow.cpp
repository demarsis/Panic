#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // load all maps
    loadMapPtrs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMapPtrs()
{
    std::vector<MapGeneratorPtr> mapgens = AllMapGenerators::get();
    for (MapGeneratorPtr mapgen : mapgens)
    {
        if (mapgen)
        {
            QVariant data = QVariant::fromValue(mapgen);
            ui->comboBoxMap->addItem(mapgen->name(), data);
        }
    }
}

void MainWindow::loadFloor(FloorPtr floor)
{
    if (!floor) return;
    ui->openGLWidget->setFloor(floor);
    ui->openGLWidget->update();
}

void MainWindow::on_pushButtonLoadMap_clicked()
{
    QVariant data = ui->comboBoxMap->currentData();
    if (!data.isValid()) return;
    if (data.isNull()) return;

    MapGeneratorPtr mapPtr = data.value<MapGeneratorPtr>();
    if (!mapPtr) return;

    // generate new map
    currentMap = mapPtr->generate();

    // temp
    loadFloor(currentMap->getFloors()[0]);
}

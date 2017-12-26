#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // load all maps
    loadMapPtrs();

    // connections
    connect(ui->pushButtonStartPause, SIGNAL(started()), this, SLOT(onStartedSimulation()));
    connect(ui->pushButtonStartPause, SIGNAL(paused()), this, SLOT(onPausedSimulation()));
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

void MainWindow::loadMap(MapGeneratorPtr mapPtr)
{
    if (!mapPtr) return;

    // clear previos map
    ui->listWidgetFloor->clear();

    // generate new map
    currentMap = mapPtr->generate();
    Floors &floors = currentMap->getFloors();

    // load floor list
    for (size_t i = 0; i < floors.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem(floors[i]->getName());
        item->setData(Qt::UserRole, i);
        ui->listWidgetFloor->addItem(item);
    }

    // show first floor
    if (!floors.empty()) toggleFloor(floors[0]);
}

void MainWindow::toggleFloor(FloorPtr floor)
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
    loadMap(mapPtr);
}

void MainWindow::on_listWidgetFloor_currentRowChanged(int currentRow)
{
    (void)currentRow;
    QListWidgetItem *item = ui->listWidgetFloor->currentItem();
    if (!item) return;

    size_t floorIndex = item->data(Qt::UserRole).toInt();
    Floors &floors = currentMap->getFloors();
    if (floorIndex >= floors.size()) return;

    toggleFloor(floors[floorIndex]);
}

void MainWindow::onStartedSimulation()
{
    ui->labelStopwatch->start();
}

void MainWindow::onPausedSimulation()
{
    ui->labelStopwatch->pause();
}

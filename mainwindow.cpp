#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // load all maps
    loadAllAvialableMaps();

    // connections
    connect(ui->pushButtonStartPause, SIGNAL(started()), this, SLOT(calledStartedSimulation()));
    connect(ui->pushButtonStartPause, SIGNAL(paused()), this, SLOT(calledPausedSimulation()));
    connect(ui->pushButtonReset, SIGNAL(clicked(bool)), this, SLOT(calledResetSimulation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAllAvialableMaps()
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

void MainWindow::showFloorList()
{
    // clear previos floor list
    ui->listWidgetFloor->clear();

    if (!simulator) return;
    MapPtr map = simulator->getMap();
    if (!map) return;
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

    // unblock controlling panel
    ui->groupBoxSimulationControl->setEnabled(true);
}

void MainWindow::newSimulation()
{
    simulator = std::make_shared<Simulator>(currentMap);
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

    // get generator
    MapGeneratorPtr mapPtr = data.value<MapGeneratorPtr>();
    if (!mapPtr) return;

    // generate new map
    currentMap = mapPtr->generate();
    if (!currentMap) return;

    // create simulation
    newSimulation();
    showFloorList();
}

void MainWindow::on_listWidgetFloor_currentRowChanged(int currentRow)
{
    (void)currentRow;
    QListWidgetItem *item = ui->listWidgetFloor->currentItem();
    if (!item) return;

    size_t floorIndex = item->data(Qt::UserRole).toInt();
    MapPtr map = simulator->getMap();
    if (!map) return;
    Floors &floors = map->getFloors();
    if (floorIndex >= floors.size()) return;

    toggleFloor(floors[floorIndex]);
}

void MainWindow::calledStartedSimulation()
{
    ui->labelStopwatch->start();
}

void MainWindow::calledPausedSimulation()
{
    ui->labelStopwatch->pause();
}

void MainWindow::calledResetSimulation()
{
    ui->pushButtonStartPause->pause();
    ui->labelStopwatch->reset();
}

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

void MainWindow::loadCurrentSimulatorIntoGUI()
{
    // clear previos floor list
    ui->listWidgetFloor->clear();

    // reset start/pause button
    ui->pushButtonStartPause->resetToUnpausedState();

    // get list of floors
    if (!simulator) return;
    MapPtr map = simulator->getMap();
    if (!map) return;
    Floors &floors = currentGeneratedMap->getFloors();

    // load floor list into the floor QList
    for (size_t i = 0; i < floors.size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem(floors[i]->getName());
        item->setData(Qt::UserRole, i);
        ui->listWidgetFloor->addItem(item);
    }

    // show first floor
    if (!floors.empty()) toggleFloor(floors[0]);

    // set stopwatch
    ui->labelStopwatch->setStopwatch(simulator->getStopwatch());

    // unblock controlling panel
    ui->groupBoxSimulationControl->setEnabled(true);
}

void MainWindow::newSimulation()
{
    simulator = std::make_shared<Simulator>(currentGeneratedMap);
}

void MainWindow::toggleFloor(FloorPtr floor)
{
    if (!floor) return;
    ui->openGLWidget->setFloor(floor);
    ui->openGLWidget->update();
}

void MainWindow::on_pushButtonGenerateMap_clicked()
{
    QVariant data = ui->comboBoxMap->currentData();
    if (!data.isValid()) return;
    if (data.isNull()) return;

    // get generator
    MapGeneratorPtr mapPtr = data.value<MapGeneratorPtr>();
    if (!mapPtr) return;

    // generate new map
    currentGeneratedMap = mapPtr->generate();
    if (!currentGeneratedMap) return;

    // create simulation
    newSimulation();
    loadCurrentSimulatorIntoGUI();
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
    simulator->start();
}

void MainWindow::calledPausedSimulation()
{
    simulator->pause();
}

void MainWindow::calledResetSimulation()
{
    newSimulation();
    loadCurrentSimulatorIntoGUI();
}

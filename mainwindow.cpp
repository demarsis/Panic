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
    connect(ui->sliderMenWomen, SIGNAL(valueChanged(int)), this, SLOT(updateManWomenPercents()));
    connect(ui->sliderChildren, SIGNAL(valueChanged(int)), this, SLOT(updateAgePercents()));
    connect(ui->sliderAdults, SIGNAL(valueChanged(int)), this, SLOT(updateAgePercents()));
    connect(ui->sliderElderlies, SIGNAL(valueChanged(int)), this, SLOT(updateAgePercents()));
    connect(ui->sliderFullness, SIGNAL(valueChanged(int)), this, SLOT(updateFullnessPercents()));

    // some gui issues
    updateManWomenPercents();
    updateAgePercents();
    updateFullnessPercents();
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
    Floors &floors = simulator->getMap()->getFloors();

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

MapCharacteristics MainWindow::createMapCharacteristicsFromGUI()
{
    // age
    int children, adults, elderlies;
    getAgePercentsFromGUI(children, adults, elderlies);

    ProbabilityRelation<AgeType> ageProbs;
    ageProbs.addProbs(AgeTypeChild, children);
    ageProbs.addProbs(AgeTypeAdult, adults);
    ageProbs.addProbs(AgeTypeElderly, elderlies);

    // gender
    int men, women;
    getGenderPercentsFromGUI(men, women);

    ProbabilityRelation<GenderType> genderProbs;
    genderProbs.addProbs(GenderTypeMale, men);
    genderProbs.addProbs(GenderTypeFemale, women);

    // creation probability
    int fullness;
    getFullnessPercentsFromGUI(fullness);

    ProbabilityRelation<bool> creationProbs;
    creationProbs.addProbs(true, fullness);
    creationProbs.addProbs(false, 100 - fullness);

    // create generator
    return MapCharacteristics(ageProbs, genderProbs, creationProbs);
}

void MainWindow::toggleFloor(FloorPtr floor)
{
    if (!floor) return;
    ui->openGLWidget->setFloor(floor);
    ui->openGLWidget->update();
}

void MainWindow::getGenderPercentsFromGUI(int &men, int &women)
{
    men = 100 - ui->sliderMenWomen->value();
    women = 100 - men;
}

void MainWindow::getAgePercentsFromGUI(int &children, int &adults, int &elderlies)
{
    children = ui->sliderChildren->value();
    adults = ui->sliderAdults->value();
    elderlies = ui->sliderElderlies->value();

    if ((children == adults) && (adults == elderlies))
    {
        children = 100;
        adults = 100;
        elderlies = 100;
    }

    int sum = children + adults + elderlies;

    children = (children * 100) / sum;
    adults = (adults * 100) / sum;
    elderlies = (elderlies * 100) / sum;
}

void MainWindow::getFullnessPercentsFromGUI(int &fullness)
{
    fullness = ui->sliderFullness->value();
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
    currentGeneratedMap = mapPtr->generate(createMapCharacteristicsFromGUI());
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

void MainWindow::updateManWomenPercents()
{
    int men, women;
    getGenderPercentsFromGUI(men, women);

    QString str = "Мужчины: " + QString::number(men) + "%, " +
                  "женщины: " + QString::number(women) + "%";
    ui->labelMenWomenPercents->setText(str);
}

void MainWindow::updateAgePercents()
{
    int children, adults, elderlies;
    getAgePercentsFromGUI(children, adults, elderlies);

    QString str = "Дети: " + QString::number(children) + "%, " +
                  "взлослые: " + QString::number(adults) + "%, " +
                  "пожилые: " + QString::number(elderlies) + "%";
    ui->labelAgePercents->setText(str);
}

void MainWindow::updateFullnessPercents()
{
    int fullness;
    getFullnessPercentsFromGUI(fullness);

    QString str = "Заполненность помещений: " + QString::number(fullness) + "%";
    ui->labelFullness->setText(str);
}

void MainWindow::on_pushButtonNext_clicked()
{
    MapPtr map = simulator->getMap();
    if (!map) return;

    for (FloorPtr &floor : map->getFloors())
    {
        if (!floor) continue;
        for (HumanPtr &human : floor->getHumanList())
        {
            if (!human) continue;

            // get movement vector
            Vector vec = HumanVector::getHumanVector(human, floor);

            // set new position
            const PositionF &oldPos = human->getPosition();
            PositionF newPos(oldPos.x + vec.getX(), oldPos.y + vec.getY());
            human->setPosition(newPos);
        }
    }

    ui->openGLWidget->update();
}

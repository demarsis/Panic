#include "simulationreport.h"

SimulationReport::SimulationReport(const QString &filename, SimulatorPtr simulator)
    : filename(filename),
      simulator(simulator),
      report(filename)
{
}

void SimulationReport::generate()
{
    if (!simulator) return;
    MapPtr &map = simulator->getMap();
    if (!map) return;

    int floorNumber = 1;
    generateTitle(map->getName());
    for (FloorPtr &floor : map->getFloors())
    {
        generateFloor(floor, floorNumber);
        floorNumber++;
    }
}

void SimulationReport::generateTitle(const QString &mapName)
{
    QFont font("Times new roman");
    font.setPixelSize(400);

    QString title("Результаты симуляции для " + mapName);

    report.addString(title, font, Qt::AlignHCenter);
    report.addString("", font, Qt::AlignHCenter);
}

void SimulationReport::generateFloor(FloorPtr &floor, int floorNumber)
{
    if (!floor) return;

    // main font
    QFont mainTextFont("Times new roman");
    mainTextFont.setPixelSize(200);
    QFont largeTextFont("Times new roman");
    largeTextFont.setPixelSize(300);
    QFont smallTextFont("Times new roman");
    smallTextFont.setPixelSize(50);

    ///////////////
    /// floor name
    ///////////////
    report.addString(QString::number(floorNumber) + ". " + floor->getName(),
                     largeTextFont, Qt::AlignHCenter);
    report.addString("", largeTextFont, Qt::AlignHCenter);


    // human count
    int startHumanCount = floor->getStartHumanCount();
    report.addString("    Количество людей на этаже: " + QString::number(startHumanCount),
                     mainTextFont, Qt::AlignLeft);
    report.addString("", smallTextFont, Qt::AlignHCenter);

    // finish human count
    int finishHumanCount = startHumanCount - floor->getHumanList().size();
    report.addString("    Количество людей, достигших выхода: " + QString::number(finishHumanCount),
                     mainTextFont, Qt::AlignLeft);
    report.addString("", smallTextFont, Qt::AlignHCenter);

    // simulation time
    if (simulator && simulator->getStopwatch())
    {
        QString simTime = simulator->getStopwatch()->toString();
        report.addString("    Общее время симуляции: " + simTime,
                         mainTextFont, Qt::AlignLeft);
        report.addString("", smallTextFont, Qt::AlignHCenter);
    }

    // link to heat map
    report.addString("", largeTextFont, Qt::AlignHCenter);
    report.addString("    На рисунке " + QString::number(floorNumber) + " представлена тепловая карта столкновений людей:",
                     mainTextFont, Qt::AlignLeft);
    report.addString("", largeTextFont, Qt::AlignHCenter);

    // insert heatmap image
    QImage floorimage;
    if (floor->getFloorImage())
    {
        floorimage = floor->getFloorImage()->getImage();
    }

    QPainter painter(&floorimage);
    QImage heatmap = PushesImage::pushesMapToImage(floor->getPushesMap(), floorimage.size());

    painter.drawImage(0, 0, heatmap);
    report.addImage(floorimage);

    // insert picture caption
    report.addString("", mainTextFont, Qt::AlignHCenter);
    report.addString("Рисунок " + QString::number(floorNumber) +
                     " - Тепловая карта этажа " + floor->getName(),
                     mainTextFont, Qt::AlignHCenter);
    report.addString("", smallTextFont, Qt::AlignHCenter);
}

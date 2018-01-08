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

    generateTitle(map->getName());
    for (FloorPtr &floor : map->getFloors())
    {
        generateFloor(floor);
    }
    generateTitle(map->getName());
}

void SimulationReport::generateTitle(const QString &mapName)
{
    QFont font("Times new roman");
    font.setPixelSize(500);

    QString title("Результаты симуляции для помещения \"" + mapName + "\"");
    report.addString(title, font, Qt::AlignHCenter);
}

void SimulationReport::generateFloor(FloorPtr &floor)
{
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
}

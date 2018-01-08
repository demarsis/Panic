#ifndef SIMULATIONREPORT_H
#define SIMULATIONREPORT_H

#include <QString>
#include <QFont>
#include "simulation/simulator.h"
#include "report.h"
#include "map/floor.h"
#include "map/floor.h"
#include "map/pushesimage.h"

class SimulationReport
{
    QString filename;
    SimulatorPtr simulator;

    Report report;

public:
    SimulationReport(const QString &filename, SimulatorPtr simulator);

    void generate();

private:
    void generateTitle(const QString &mapName);
    void generateFloor(FloorPtr &floor);
};

#endif // SIMULATIONREPORT_H

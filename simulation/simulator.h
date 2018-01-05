#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QTimer>
#include <memory>
#include "map/map.h"
#include "map/floor.h"
#include "human/human.h"
#include "stopwatch.h"
#include "penaltywaybuilder.h"
#include "graph/simulatorwidget.h"
#include "humanvector.h"
#include "probability/probabilityrelation.h"

class Simulator : public QObject
{
    Q_OBJECT

    SimulatorWidget &openGLWidget;
    MapPtr map;
    std::vector<HumanPtr> finishedHumanList;

    StopwatchPtr stopwatch;
    QTimer timer;

public:
    Simulator(SimulatorWidget &openGLWidget, MapPtr map);
    MapPtr getMap();
    StopwatchPtr getStopwatch();

    void start();
    void pause();

private slots:
    void onTimer();

private:
    void updateHumanVectors();
    void disapeareHumans();
};

typedef std::shared_ptr<Simulator> SimulatorPtr;

#endif // SIMULATOR_H

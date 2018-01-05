#include "simulator.h"

Simulator::Simulator(SimulatorWidget &openGLWidget, MapPtr map)
    : openGLWidget(openGLWidget)
{
    if (map)
    {
        this->map = map->clone();

        // generate way penalty for cell matrix for each floor
        for (FloorPtr floor : this->map->getFloors())
        {
            PenaltyWayBuilder::generate(floor);
        }
    }
    stopwatch = std::make_shared<Stopwatch>();

    timer.setInterval(17);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

MapPtr Simulator::getMap()
{
    return map;
}

StopwatchPtr Simulator::getStopwatch()
{
    return stopwatch;
}

void Simulator::start()
{
    stopwatch->start();
    timer.start();
}

void Simulator::pause()
{
    stopwatch->pause();
    timer.stop();
}

void Simulator::onTimer()
{
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

    openGLWidget.update();
}


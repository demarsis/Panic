#include "simulator.h"

Simulator::Simulator(MapPtr map)
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
}

void Simulator::pause()
{
    stopwatch->pause();
}


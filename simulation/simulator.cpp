#include "simulator.h"

Simulator::Simulator(MapPtr map)
{
    if (map)
    {
        this->map = map->clone();
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


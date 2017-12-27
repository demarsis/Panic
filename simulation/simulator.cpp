#include "simulator.h"

Simulator::Simulator(MapPtr map)
{
    if (map)
    {
        this->map = map->clone();
    }
}

MapPtr Simulator::getMap()
{
    return map;
}

Stopwatch &Simulator::getStopwatch()
{
    return stopwatch;
}


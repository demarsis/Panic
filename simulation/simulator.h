#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <memory>
#include "map/map.h"
#include "map/floor.h"
#include "human/human.h"
#include "stopwatch.h"

class Simulator
{
    MapPtr map;
    Stopwatch stopwatch;

public:
    Simulator(MapPtr map);
    MapPtr getMap();
    Stopwatch &getStopwatch();
};

typedef std::shared_ptr<Simulator> SimulatorPtr;

#endif // SIMULATOR_H

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "map/map.h"
#include "map/floor.h"
#include "human/human.h"

class Simulator
{
    MapPtr map;
public:
    Simulator(MapPtr map);
};

#endif // SIMULATOR_H

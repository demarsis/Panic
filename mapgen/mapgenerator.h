#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "map/map.h"
#include "human/human.h"

class MapGenerator
{
public:
    virtual MapPtr generate() const = 0;
};

#endif // MAPGENERATOR_H

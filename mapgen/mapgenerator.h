#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "map/map.h"
#include "human/human.h"
#include <memory>
#include "map/floor.h"
#include "imagepositions.h"

class MapGenerator
{
public:
    virtual MapPtr generate() const = 0;
};

#endif // MAPGENERATOR_H

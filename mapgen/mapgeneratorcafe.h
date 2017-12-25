#ifndef MAPGENERATORCAFE_H
#define MAPGENERATORCAFE_H

#include "mapgenerator.h"
#include "humanlistgenerator.h"
#include "map/mappositions.h"

class MapGeneratorCafe : public MapGenerator
{
public:
    virtual MapPtr generate() const;
};

#endif // MAPGENERATORCAFE_H

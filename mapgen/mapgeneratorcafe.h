#ifndef MAPGENERATORCAFE_H
#define MAPGENERATORCAFE_H

#include "mapgenerator.h"
#include "humanlistgenerator.h"
#include "imagepositions.h"
#include "imagebarriers.h"
#include "map/mappositions.h"
#include "map/mapbarriers.h"

class MapGeneratorCafe : public MapGenerator
{
public:
    virtual MapPtr generate() const;
};

#endif // MAPGENERATORCAFE_H

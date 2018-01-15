#ifndef MAPGENERATORTHEATERBLOCKED_H
#define MAPGENERATORTHEATERBLOCKED_H

#include "mapgenerator.h"
#include "floorgenerator.h"
#include "floordescriptor.h"

class MapGeneratorTheaterBlocked : public MapGenerator
{
public:
    virtual MapPtr generate(const MapCharacteristics &mapChar) const;
    virtual QString name() const;
};

#endif // MAPGENERATORTHEATERBLOCKED_H

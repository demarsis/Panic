#ifndef MAPGENERATORTHEATER_H
#define MAPGENERATORTHEATER_H

#include "mapgenerator.h"
#include "floorgenerator.h"
#include "floordescriptor.h"

class MapGeneratorTheater : public MapGenerator
{
public:
    virtual MapPtr generate(const MapCharacteristics &mapChar) const;
    virtual QString name() const;
};

#endif // MAPGENERATORTHEATER_H

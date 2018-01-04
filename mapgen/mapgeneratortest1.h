#ifndef MAPGENERATORTEST1_H
#define MAPGENERATORTEST1_H

#include "mapgenerator.h"
#include "floorgenerator.h"
#include "floordescriptor.h"

class MapGeneratorTest1 : public MapGenerator
{
public:
    virtual MapPtr generate(const MapCharacteristics &mapChar) const;
    virtual QString name() const;
};

#endif // MAPGENERATORTEST1_H

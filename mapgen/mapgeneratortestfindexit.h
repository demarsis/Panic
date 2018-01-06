#ifndef MAPGENERATORTESTFINDEXIT_H
#define MAPGENERATORTESTFINDEXIT_H

#include "mapgenerator.h"
#include "floorgenerator.h"
#include "floordescriptor.h"

class MapGeneratorTestFindExit : public MapGenerator
{
public:
    virtual MapPtr generate(const MapCharacteristics &mapChar) const;
    virtual QString name() const;
};

#endif // MAPGENERATORTESTFINDEXIT_H

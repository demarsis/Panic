#ifndef MAPGENERATORCAFE_H
#define MAPGENERATORCAFE_H

#include "mapgenerator.h"
#include "floorgenerator.h"
#include "floordescriptor.h"

class MapGeneratorCafe : public MapGenerator
{
public:
    virtual MapPtr generate() const;
    virtual QString name() const;
};

#endif // MAPGENERATORCAFE_H

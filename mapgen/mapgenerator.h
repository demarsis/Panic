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
    virtual QString name() const = 0;
};

typedef std::shared_ptr<MapGenerator> MapGeneratorPtr;

Q_DECLARE_METATYPE(MapGeneratorPtr)

#endif // MAPGENERATOR_H

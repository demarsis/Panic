#include "map.h"

Map::Map(const QString &name, Floors floors)
    : name(name), floors(floors)
{
}

Floors &Map::getFloors()
{
    return floors;
}

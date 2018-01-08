#include "map.h"

Map::Map(const QString &name, Floors floors)
    : name(name), floors(floors)
{
}

Floors &Map::getFloors()
{
    return floors;
}

std::shared_ptr<Map> Map::clone() const
{
    Floors fls;
    for (const FloorPtr f : floors)
    {
        fls.push_back(f->clone());
    }
    return std::make_shared<Map>(name, fls);
}

const QString &Map::getName() const
{
    return name;
}

#ifndef MAP_H
#define MAP_H

#include <memory>
#include "common/types.h"
#include <QString>
#include <vector>
#include "floor.h"

typedef std::vector<FloorPtr> Floors;

class Map
{
    const QString name;
    Floors floors;

public:
    Map(const QString &name, Floors floors);
    Floors &getFloors();
    std::shared_ptr<Map> clone() const;
    const QString &getName() const;
};

typedef std::shared_ptr<Map> MapPtr;

#endif // MAP_H

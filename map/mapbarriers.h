#ifndef MAPBARRIERS_H
#define MAPBARRIERS_H

#include "barrier.h"
#include "common/types.h"
#include <vector>

class MapBarriers
{
    int width, height;
    std::vector<std::pair<Position, BarrierType>> barriers;

public:
    MapBarriers(const std::vector<std::pair<Position, BarrierType>> &barriers);
    const std::vector<std::pair<Position, BarrierType>> &getBarriersList() const;
};

#endif // MAPBARRIERS_H

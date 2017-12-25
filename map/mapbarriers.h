#ifndef MAPBARRIERS_H
#define MAPBARRIERS_H

#include "barrier.h"
#include "common/types.h"
#include <vector>

class MapBarriers
{
    std::vector<std::pair<Position, BarrierType>> barriers;

public:
    MapBarriers(const std::vector<std::pair<Position, BarrierType>> &barriers);
    const std::vector<std::pair<Position, BarrierType>> &getBarrierList() const;

    BarrierType getBarrierType(int x, int y) const;
};

#endif // MAPBARRIERS_H

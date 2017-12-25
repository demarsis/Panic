#include "mapbarriers.h"

MapBarriers::MapBarriers(const std::vector<std::pair<Position, BarrierType> > &barriers)
    : barriers(barriers)
{
}

const std::vector<std::pair<Position, BarrierType> > &MapBarriers::getBarrierList() const
{
    return barriers;
}

BarrierType MapBarriers::getBarrierType(int x, int y) const
{
    for (const auto pair : barriers)
    {
        const Position &p = pair.first;
        if ((p.x == x) && (p.y == y)) return pair.second;
    }
    return BarrierTypeNo;
}


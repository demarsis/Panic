#include "mapbarriers.h"

MapBarriers::MapBarriers(const std::vector<std::pair<Position, BarrierType> > &barriers)
    : barriers(barriers)
{
}

const std::vector<std::pair<Position, BarrierType> > &MapBarriers::getBarriersList() const
{
    return barriers;
}


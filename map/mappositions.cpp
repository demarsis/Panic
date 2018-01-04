#include "mappositions.h"

MapPositions::MapPositions(const std::vector<Position> &pos)
    : pos(pos)
{
}

const std::vector<Position> &MapPositions::getPositionList() const
{
    return pos;
}

#include "mappositions.h"

MapPositions::MapPositions(const std::vector<Position> &pos)
    : pos(pos)
{
}

bool MapPositions::hasFinishPosition(int x, int y) const
{
    for (const Position &p : pos)
    {
        if ((p.x == x) && (p.y == y)) return true;
    }
    return false;
}

const std::vector<Position> &MapPositions::getPositionList() const
{
    return pos;
}

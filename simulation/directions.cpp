#include "directions.h"

Directions::Directions(bool centralCell)
{
    dirs.push_back(std::make_pair(Position(-1, -1), Vector(-0.707, -0.707)));
    dirs.push_back(std::make_pair(Position(-1,  0), Vector(    -1,      0)));
    dirs.push_back(std::make_pair(Position(-1, +1), Vector(-0.707, +0.707)));

    dirs.push_back(std::make_pair(Position( 0, -1), Vector(     0,     -1)));
    if (centralCell)
    {
        dirs.push_back(
                   std::make_pair(Position( 0,  0), Vector(     0,      0)));
    }
    dirs.push_back(std::make_pair(Position( 0, +1), Vector(     0,     +1)));

    dirs.push_back(std::make_pair(Position(+1, -1), Vector(+0.707, -0.707)));
    dirs.push_back(std::make_pair(Position(+1,  0), Vector(    +1,      0)));
    dirs.push_back(std::make_pair(Position(+1, +1), Vector(+0.707, +0.707)));
}

const std::vector<Directions::DirVector> &Directions::getAllDirections() const
{
    return dirs;
}

const std::vector<Position> Directions::getAllPositions() const
{
    std::vector<Position> result;
    for (const DirVector &dv : dirs)
    {
        result.push_back(dv.first);
    }
    return result;
}


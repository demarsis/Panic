#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "common/types.h"
#include <utility>
#include "vector.h"
#include <vector>

class Directions
{
    typedef std::pair<Position, Vector> DirVector;
    std::vector<DirVector> dirs;

public:
    Directions();
    const std::vector<DirVector> &getAllDirections() const;
};

#endif // DIRECTIONS_H

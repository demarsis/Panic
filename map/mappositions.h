#ifndef FINISHPOSITIONS_H
#define FINISHPOSITIONS_H

#include "common/types.h"
#include <vector>

class MapPositions
{
    std::vector<Position> pos;

public:
    MapPositions(const std::vector<Position> &pos);
    const std::vector<Position> &getPositionList() const;
};

#endif // FINISHPOSITIONS_H

#ifndef HUMANVECTOR_H
#define HUMANVECTOR_H

#include "common/types.h"
#include "human/human.h"
#include "map/floor.h"
#include "directions.h"
#include <algorithm>

class HumanVector
{
    static Directions dirs;

public:
    static Vector getHumanVector(HumanPtr &human, FloorPtr &floor);

private:
    static Vector getIntentionVector(HumanPtr &human, FloorPtr &floor);

    static std::vector<CellPtr> getHumanCells(HumanPtr &human, FloorPtr &floor);
    static Penalty getCellsPenalty(FloorPtr &floor, const std::vector<CellPtr> &cells, const Position &offset);
};

#endif // HUMANVECTOR_H

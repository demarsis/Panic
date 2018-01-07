#ifndef HUMANVECTOR_H
#define HUMANVECTOR_H

#include "common/types.h"
#include "human/human.h"
#include "map/floor.h"
#include "directions.h"
#include <algorithm>
#include "common/defines.h"
#include <vector>

class HumanVector
{
    static Directions dirs;

public:
    static Vector getIntentionVector(HumanPtr &human, FloorPtr &floor);

    static std::vector<CellPtr> getHumanCells(HumanPtr &human, FloorPtr &floor);
    static Penalty getCellsPenalty(FloorPtr &floor, const std::vector<CellPtr> &cells, const Position &offset);
    static bool isNewPositionIntersectedWithOther(const HumanPtr &human, const Vector &vec, const HumanPtr &other);
    static Vector getPushesVector(const HumanPtr &human, const HumanPtr &other);
};

#endif // HUMANVECTOR_H

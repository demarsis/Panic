#ifndef PENALTYWAYBUILDER_H
#define PENALTYWAYBUILDER_H

#include "map/floor.h"
#include "map/cell.h"
#include "directions.h"

class PenaltyWayBuilder
{
public:
    static bool generate(FloorPtr floor);

private:
    // Position is relative!
    static std::vector<std::pair<CellPtr, Position>> getNeighborCells(FloorPtr floor, CellPtr cell);

};

#endif // PENALTYWAYBUILDER_H

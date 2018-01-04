#ifndef PENALTYWAYBUILDER_H
#define PENALTYWAYBUILDER_H

#include "map/floor.h"
#include "map/cell.h"
#include "directions.h"
#include "common/consolelogger.h"

class PenaltyWayBuilder
{
public:
    static bool generate(FloorPtr floor);
};

#endif // PENALTYWAYBUILDER_H

#include "cell.h"

Cell::Cell(const Position &pos, const Barrier &barrier, const Exit &exit)
    : pos(pos),
      barrier(barrier),
      exit(exit),
      addData(0, 0)
{
}

const Position &Cell::getPosition() const
{
    return pos;
}

const Barrier &Cell::getBarrier() const
{
    return barrier;
}

const Exit &Cell::getExit() const
{
    return exit;
}

CellAdditionalData &Cell::getAdditionalData()
{
    return addData;
}

#include "cell.h"

Cell::Cell(const Position &pos, const Barrier &barrier, const Exit &exit)
    : pos(pos),
      barrier(barrier),
      exit(exit),
      addData(barrier.getCellPenalty(), PENALTY_MAX)
{
    // if this cell is an exit - way penalty is zero
    if (getExit().isExit())
    {
        addData.wayPenalty = PENALTY_ZERO;
    }
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

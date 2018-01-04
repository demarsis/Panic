#include "cell.h"

Cell::Cell(const Position &pos, const Barrier &barrier, const Exit &exit)
    : pos(pos),
      barrier(barrier),
      exit(exit),
      addData(barrier.getCellPenalty(), PENALTY_MAX)
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

void Cell::setBarrier(BarrierType barrierType)
{
    barrier.setType(barrierType);
    addData.cellPenalty = barrier.getCellPenalty();
}

const Exit &Cell::getExit() const
{
    return exit;
}

void Cell::setExit(ExitType exitType)
{
    exit.setExitType(exitType);
    addData.wayPenalty = exit.getStartWayPenalty();
}

CellAdditionalData &Cell::getAdditionalData()
{
    return addData;
}

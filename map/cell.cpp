#include "cell.h"

Cell::Cell(const Barrier &barrier, const Exit &exit)
    : penalty(0),
      cost(0),
      barrier(barrier),
      exit(exit)
{
}

CellPenalty Cell::getPenalty() const
{
    return penalty;
}

void Cell::setPenalty(CellPenalty penalty)
{
    this->penalty = penalty;
}

CellCost Cell::getCost() const
{
    return cost;
}

void Cell::setCost(CellCost cost)
{
    this->cost = cost;
}

void Cell::resetCost()
{
    setCost(0);
}

const Barrier &Cell::getBarrier() const
{
    return barrier;
}

const Exit &Cell::getExit() const
{
    return exit;
}

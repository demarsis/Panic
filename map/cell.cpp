#include "cell.h"

Cell::Cell(bool exit)
    : penalty(0),
      cost(0),
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

bool Cell::isExit() const
{
    return exit;
}

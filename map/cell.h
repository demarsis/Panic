#ifndef CELL_H
#define CELL_H

#include <memory>
#include "common/types.h"
#include "barrier.h"

class Cell
{
    CellPenalty penalty;
    CellCost cost;
    Barrier barrier;

public:
    Cell(const Barrier &barrier);

    CellPenalty getPenalty() const;
    void setPenalty(CellPenalty penalty);

    CellCost getCost() const;
    void setCost(CellCost cost);
    void resetCost();

    const Barrier &getBarrier() const;
};

typedef std::shared_ptr<Cell> CellPtr;

#endif // CELL_H

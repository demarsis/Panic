#ifndef CELL_H
#define CELL_H

#include <memory>
#include "common/types.h"
#include "barrier.h"
#include "exit.h"

class Cell
{
    CellPenalty penalty;
    CellCost cost;
    Barrier barrier;
    Exit exit;

public:
    Cell(const Barrier &barrier, const Exit &exit);

    CellPenalty getPenalty() const;
    void setPenalty(CellPenalty penalty);

    CellCost getCost() const;
    void setCost(CellCost cost);
    void resetCost();

    const Barrier &getBarrier() const;
    const Exit &getExit() const;
};

typedef std::shared_ptr<Cell> CellPtr;

#endif // CELL_H

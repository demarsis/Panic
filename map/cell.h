#ifndef CELL_H
#define CELL_H

#include <memory>
#include "common/types.h"

class Cell
{
    CellPenalty penalty;
    CellCost cost;
    bool exit;

public:
    Cell(bool exit);

    CellPenalty getPenalty() const;
    void setPenalty(CellPenalty penalty);

    CellCost getCost() const;
    void setCost(CellCost cost);
    void resetCost();

    bool isExit() const;
};

typedef std::shared_ptr<Cell> CellPtr;

#endif // CELL_H

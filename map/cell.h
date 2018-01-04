#ifndef CELL_H
#define CELL_H

#include <memory>
#include "common/types.h"
#include "barrier.h"
#include "exit.h"

struct CellAdditionalData
{
    Penalty cellPenalty;
    Penalty wayPenalty;

    int visited;

    CellAdditionalData(Penalty cellPenalty, Penalty wayPenalty)
        : cellPenalty(cellPenalty),
          wayPenalty(wayPenalty),
          visited(0)
    {
    }

    void resetVisited()
    {
        visited = 0;
    }
};

class Cell
{
    Position pos;
    Barrier barrier;
    Exit exit;

    CellAdditionalData addData;

public:
    Cell(const Position &pos, const Barrier &barrier, const Exit &exit);

    const Position &getPosition() const;
    const Barrier &getBarrier() const;
    void setBarrier(BarrierType barrierType);
    const Exit &getExit() const;
    void setExit(ExitType exitType);

    CellAdditionalData &getAdditionalData();
};

typedef std::shared_ptr<Cell> CellPtr;

#endif // CELL_H

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

    bool visited;

    CellAdditionalData(Penalty cellPenalty, Penalty wayPenalty)
        : cellPenalty(cellPenalty),
          wayPenalty(wayPenalty),
          visited(false)
    {
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
    const Exit &getExit() const;

    CellAdditionalData &getAdditionalData();
};

typedef std::shared_ptr<Cell> CellPtr;

#endif // CELL_H

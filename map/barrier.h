#ifndef BARRIER_H
#define BARRIER_H

#include "common/types.h"

enum BarrierType
{
    BarrierTypeNo,
    BarrierTypeCritical,
    BarrierTypeWall
};

class Barrier
{
    BarrierType barrierType;

public:
    Barrier(BarrierType barrierType);
    BarrierType getType() const;
    Penalty getCellPenalty() const;
};

#endif // BARRIER_H

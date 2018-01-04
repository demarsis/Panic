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
    void setType(BarrierType barrierType);
    Penalty getCellPenalty() const;
};

#endif // BARRIER_H

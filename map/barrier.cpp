#include "barrier.h"

Barrier::Barrier(BarrierType barrierType)
    : barrierType(barrierType)
{
}

BarrierType Barrier::getType() const
{
    return barrierType;
}

Penalty Barrier::getCellPenalty() const
{
    switch (getType())
    {
    case BarrierTypeNo:
        return PENALTY_FREE_CELL;
    case BarrierTypeCritical:
        return PENALTY_CRITICAL_CELL;
    case BarrierTypeWall:
        return PENALTY_WALL_CELL;
    }
    return PENALTY_WALL_CELL;
}

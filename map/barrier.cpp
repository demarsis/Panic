#include "barrier.h"

Barrier::Barrier(BarrierType barrierType)
    : barrierType(barrierType)
{
}

BarrierType Barrier::getType() const
{
    return barrierType;
}

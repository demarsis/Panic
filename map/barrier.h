#ifndef BARRIER_H
#define BARRIER_H

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
};

#endif // BARRIER_H

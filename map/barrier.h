#ifndef BARRIER_H
#define BARRIER_H

enum BarrierType
{
    No,
    Critical,
    Wall
};

class Barrier
{
    BarrierType barrierType;

public:
    Barrier(BarrierType barrierType);
    BarrierType getType() const;
};

#endif // BARRIER_H

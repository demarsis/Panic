#ifndef MAPBARRIERS_H
#define MAPBARRIERS_H

#include "barrier.h"
#include "common/types.h"
#include <vector>

class MapBarriers
{
    int width, height;
    std::vector<std::vector<BarrierType>> matrix;

public:
    MapBarriers(int width, int height,
                const std::vector<std::pair<Position, BarrierType>> &barriers);

    BarrierType getBarrierType(int x, int y) const;

private:
    void setBarrier(int x, int y, BarrierType type);
};

#endif // MAPBARRIERS_H

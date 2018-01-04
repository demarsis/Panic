#include "mapbarriers.h"

MapBarriers::MapBarriers(int width, int height,
                         const std::vector<std::pair<Position, BarrierType> > &barriers)
    : width(width),
      height(height)
{
    if ((width > 0) && (height > 0))
    {
        // create matrix
        matrix.resize(width);
        for (int i = 0; i < width; i++)
        {
            matrix[i].resize(height);
        }

        // fill matrix with no's
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                setBarrier(i, j, BarrierTypeNo);
            }
        }

        // fill with barriers
        for (const auto &a : barriers)
        {
            setBarrier(a.first.x, a.first.y, a.second);
        }
    }
}

BarrierType MapBarriers::getBarrierType(int x, int y) const
{
    if (x < 0) return BarrierTypeWall;
    if (x >= width) return BarrierTypeWall;
    if (y < 0) return BarrierTypeWall;
    if (y >= height) return BarrierTypeWall;

    return matrix[x][y];
}

void MapBarriers::setBarrier(int x, int y, BarrierType type)
{
    if (x < 0) return;
    if (x >= width) return;
    if (y < 0) return;
    if (y >= height) return;

    matrix[x][y] = type;
}


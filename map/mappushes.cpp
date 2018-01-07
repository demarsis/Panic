#include "mappushes.h"

MapPushes::MapPushes(int width, int height)
    : width(width),
      height(height)
{
    if ((width > 0) && (height))
    {
        pushes.resize(width);
        for (int i = 0; i < width; i++)
        {
            pushes[i].resize(height, 0);
        }
    }
}

void MapPushes::addPush(const PositionF &posf, const Vector &vec)
{
    const Position pos((int)posf.x, (int)posf.y);
    if (!isValidPosition(pos)) return;

    float push = sqrt((vec.getX() * vec.getX()) + (vec.getY() * vec.getY()));
    pushes[pos.x][pos.y] += push;
}

float MapPushes::getPush(const Position &pos) const
{
    if (!isValidPosition(pos)) return 0;
    return pushes[pos.x][pos.y];
}

Size MapPushes::getSize() const
{
    return Size(width, height);
}

bool MapPushes::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= width) return false;
    if (pos.y >= height) return false;
    return true;
}


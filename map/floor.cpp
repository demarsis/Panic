#include "floor.h"

Floor::Floor(Size size,
             QString name,
             FloorImagePtr floorImage,
             const std::vector<HumanPtr> &humanList,
             const std::vector<Position> &finishPositions)
    : size(size),
      name(name),
      floorImage(floorImage),
      humanList(humanList)
{
    if ((this->size.x > 0) && (this->size.y  > 0))
    {
        cellMatrix.resize(this->size.x);
        for (int i = 0; i < this->size.x; i++)
        {
            cellMatrix[i].resize(this->size.y);
        }
    }
    else
    {
        this->size.x = 0;
        this->size.y = 0;
    }
}

CellPtr Floor::getCell(const Position &pos)
{
    if(isValidPosition(pos))
    {
        return cellMatrix[pos.x][pos.y];
    }
    else
    {
        return CellPtr();
    }
}

bool Floor::setCell(const Position &pos, CellPtr cell)
{
    if(isValidPosition(pos))
    {
        cellMatrix[pos.x][pos.y] = cell;
        return true;
    }
    return false;
}

FloorImagePtr Floor::getFloorImage()
{
    return floorImage;
}

std::vector<HumanPtr> &Floor::getHumanList()
{
    return humanList;
}

const Size &Floor::getSize() const
{
    return size;
}

bool Floor::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= size.x) return false;
    if (pos.y >= size.y) return false;
    return true;
}

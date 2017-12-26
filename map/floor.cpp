#include "floor.h"

Floor::Floor(Size size,
             QString name,
             FloorImagePtr floorImage,
             const std::vector<HumanPtr> &humanList,
             const MapPositions &finishPositions,
             const MapBarriers &mapBarriers)
    : size(size),
      name(name),
      floorImage(floorImage),
      humanList(humanList),
      finishPositions(finishPositions),
      mapBarriers(mapBarriers)
{
    if ((this->size.x > 0) && (this->size.y  > 0))
    {
        cellMatrix.resize(this->size.x);
        for (int i = 0; i < this->size.x; i++)
        {
            cellMatrix[i].resize(this->size.y);
        }

        // fill the matrix with real Cells
        for (int i = 0; i < this->size.x; i++)
        {
            for (int j = 0; j < this->size.y; j++)
            {
                // has barrier
                BarrierType barrierType = BarrierTypeNo;

                // has exit
                ExitType exitType = ExitTypeNo;
                if (finishPositions.hasFinishPosition(i, j)) exitType = ExitTypeExit;

                // create cell
                cellMatrix[i][j] = std::make_shared<Cell>(
                            Barrier(barrierType),
                            Exit(exitType)
                            );
            }
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

CellPtr Floor::getCell(int x, int y)
{
    return getCell(Position(x, y));
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

const MapPositions &Floor::getFinishMapPositions() const
{
    return finishPositions;
}

const MapBarriers &Floor::getMapBarriers() const
{
    return mapBarriers;
}

const Size &Floor::getSize() const
{
    return size;
}

const QString &Floor::getName() const
{
    return name;
}

bool Floor::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= size.x) return false;
    if (pos.y >= size.y) return false;
    return true;
}

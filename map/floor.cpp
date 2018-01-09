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
      mapBarriers(mapBarriers),
      startHumanCount(humanList.size())
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
                // create cell
                cellMatrix[i][j] = std::make_shared<Cell>(
                                      Position(i, j),
                                      BarrierTypeNo,
                                      ExitTypeNo
                                      );
            }
        }

        // set barriers
        for (const auto &a : mapBarriers.getBarriersList())
        {
            const Position &pos = a.first;
            if (isValidPosition(pos))
            {
                CellPtr &cell = cellMatrix[pos.x][pos.y];
                cell->setBarrier(a.second);
            }
        }

        // set finishes
        for (const Position &pos : finishPositions.getPositionList())
        {
            if (isValidPosition(pos))
            {
                CellPtr &cell = cellMatrix[pos.x][pos.y];
                cell->setExit(ExitTypeExit);
            }
        }

        // create pushes map
        pushesMap = std::make_shared<MapPushes>(size.x, size.y);
    }
    else
    {
        this->size.x = 0;
        this->size.y = 0;
    }
}

CellPtr &Floor::getCell(const Position &pos)
{
    return cellMatrix[pos.x][pos.y];
}

CellPtr &Floor::getCell(int x, int y)
{
    return getCell(Position(x, y));
}

CellMatrixIterator Floor::getCellIterator()
{
    return CellMatrixIterator(cellMatrix);
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

std::shared_ptr<Floor> Floor::clone() const
{
    // clone all humans
    std::vector<HumanPtr> hl;
    for (HumanPtr h : humanList)
    {
        hl.push_back(h->clone());
    }

    // clone all floor
    FloorPtr floor = std::make_shared<Floor>(size, name, floorImage, hl,
                                             finishPositions, mapBarriers);
    return floor;
}

bool Floor::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= size.x) return false;
    if (pos.y >= size.y) return false;
    return true;
}

MapPushesPtr &Floor::getPushesMap()
{
    return pushesMap;
}

int Floor::getStartHumanCount() const
{
    return startHumanCount;
}

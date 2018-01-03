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
                CellPtr newCell = std::make_shared<Cell>(
                                      Position(i, j),
                                      Barrier(barrierType),
                                      Exit(exitType)
                                      );


                cellMatrix[i][j] = newCell;
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

void Floor::generateWayPenaltyMap()
{
    // clear update number for all cells
    for (CellMatrixIterator it(cellMatrix); it.hasNext();)
    {
        CellAdditionalData &addData = cell->getAdditionalData();
        addData.visited = 0;
    }


    // continue while have any changes
    bool wasChanges = true;
    int updateNumber = 1;
    while (wasChanges)
    {
        wasChanges = false;

        // generate vector of Cells with finish positions
        std::deque<CellPtr> cellsToUpdate;
        CellMatrixIterator it(cellMatrix);
        while (it.hasNext())
        {
            CellPtr cell = it.next();
            if (cell->getExit().isExit())
            {
                cellsToUpdate.push_back(cellsToUpdate);
            }
        }


    }
}

bool Floor::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= size.x) return false;
    if (pos.y >= size.y) return false;
    return true;
}

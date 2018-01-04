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
                BarrierType barrierType = mapBarriers.getBarrierType(i, j);

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

std::vector<CellPtr> Floor::getHumanCells(HumanPtr human)
{
    std::vector<CellPtr> result;
    if (!human) return result;

    Position center(human->getPosition().x, human->getPosition().y);
    int radius = human->getDiameter() / 2;

    Position lefttop(center.x - radius, center.y - radius);
    Position rightbottom(center.x + radius, center.y + radius);

    for (int x = lefttop.x; x <= rightbottom.x; x++)
    {
        for (int y = lefttop.y; y <= rightbottom.y; y++)
        {
            float currentRadius = sqrt((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y));
            if (currentRadius > radius) continue;

            result.push_back(getCell(x, y));
        }
    }

    return result;
}

Penalty Floor::getCellsPenalty(const std::vector<CellPtr> &cells, Position offset)
{
    Penalty result = 0;
    for (const CellPtr &cell : cells)
    {
        Position pos = cell->getPosition();
        pos.x += offset.x;
        pos.y += offset.y;

        CellPtr offsetedCell = getCell(pos);

        if (!offsetedCell)
        {
            result += PENALTY_MAX;
            continue;
        }

        result += offsetedCell->getAdditionalData().wayPenalty;
    }

    return result;
}

bool Floor::isValidPosition(const Position &pos) const
{
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x >= size.x) return false;
    if (pos.y >= size.y) return false;
    return true;
}

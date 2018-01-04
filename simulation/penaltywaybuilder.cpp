#include "penaltywaybuilder.h"

bool PenaltyWayBuilder::generate(FloorPtr floor)
{
    if (!floor) return false;
    int counter = 0;

    // continue while have any changes
    bool wasChanges = true;
    while (wasChanges)
    {
        counter++;
        ConsoleLogger::info(QString("Attempt #") + QString::number(counter));

        wasChanges = false;

        // reset visited
        CellMatrixIterator it = floor->getCellIterator();
        while (it.hasNext())
        {
            CellPtr currectCell = it.next();
            if (!currectCell) continue;
            currectCell->getAdditionalData().visited = false;
        }

        // build new way penalties
        it.reset();
        while (it.hasNext())
        {
            CellPtr currectCell = it.next();
            if (!currectCell) continue;

            if (currectCell->getAdditionalData().visited == false)
            {
                currectCell->getAdditionalData().visited = true;

                // get all it's neighbors
                std::vector<std::pair<CellPtr, Position>> neighs = getNeighborCells(floor, currectCell);

                for (const auto &a : neighs)
                {
                    CellPtr neigh = a.first;
                    if (!neigh) continue;
                    Position relativePosition = a.second;

                    // count new penalty for current cell
                    Penalty newPenalty = currectCell->getAdditionalData().wayPenalty +
                                         neigh->getAdditionalData().cellPenalty *
                                         sqrt((double)relativePosition.x * (double)relativePosition.x +
                                              (double)relativePosition.y * (double)relativePosition.y);

                    // update only if the penalty is lower then the existing one
                    if (neigh->getAdditionalData().wayPenalty > newPenalty)
                    {
                        neigh->getAdditionalData().wayPenalty = newPenalty;
                        wasChanges = true;
                    }
                }
            }
        }
    }

    return true;
}

std::vector<std::pair<CellPtr, Position> > PenaltyWayBuilder::getNeighborCells(FloorPtr floor, CellPtr cell)
{
    std::vector<std::pair<CellPtr, Position>> result;
    if (!floor) return result;
    if (!cell)  return result;

    Position cellPos = cell->getPosition();
    Directions dirs(false);
    for (const auto &a : dirs.getAllDirections())
    {
        Position neightborCellPosition(cellPos.x + a.first.x,
                                       cellPos.y + a.first.y);
        if (floor->isValidPosition(neightborCellPosition))
        {
            result.push_back(std::make_pair(floor->getCell(neightborCellPosition), a.first));
        }
    }

    return result;
}

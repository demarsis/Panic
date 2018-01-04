#include "penaltywaybuilder.h"

bool PenaltyWayBuilder::generate(FloorPtr floor)
{
    if (!floor) return false;

    // clear update number for all cells
    for (CellMatrixIterator it = floor->getCellIterator(); it.hasNext();)
    {
        CellPtr cell = it.next();
        CellAdditionalData &addData = cell->getAdditionalData();
        addData.visited = 0;
    }

    // generate vector of Cells with finish positions
    std::deque<CellPtr> finishCells;
    for (CellMatrixIterator it = floor->getCellIterator(); it.hasNext();)
    {
        CellPtr cell = it.next();
        if (cell->getExit().isExit())
        {
            finishCells.push_back(cell);
        }
    }
    if (finishCells.empty()) return false;

    // continue while have any changes
    bool wasChanges = true;
    int updateNumber = 1;
    while (wasChanges)
    {
        wasChanges = false;

        // update starts from finish positions
        std::deque<CellPtr> cellsToUpdate = finishCells;

        // continue until
        while (!cellsToUpdate.empty())
        {
            // get top cell
            CellPtr currectCell = cellsToUpdate[0];
            cellsToUpdate.pop_front();
            if (!currectCell) continue;

            if (currectCell->getAdditionalData().visited < updateNumber)
            {
                currectCell->getAdditionalData().visited = updateNumber;

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
                        cellsToUpdate.push_back(neigh);
                    }
                }
            }
        }

        // next update number
        updateNumber++;
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

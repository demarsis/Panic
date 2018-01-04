#include "penaltywaybuilder.h"

bool PenaltyWayBuilder::generate(FloorPtr floor)
{
    if (!floor) return false;
    int counter = 0;

    // neigh positions
    std::vector<Position> relativeNeighPositions = Directions(false).getAllPositions();

    // reset cells for not being visited
    CellMatrixIterator it = floor->getCellIterator();
    while (it.hasNext())
    {
        CellPtr &currectCell = it.next();
        if (!currectCell) continue;
        currectCell->getAdditionalData().resetVisited();
    }

    // cells positions need to be updated
    std::deque<Position> currentToUpdate, nextToUpdate;

    // continue while have any changes
    bool wasChanges = true;
    while (wasChanges)
    {
        ////////////////
        counter++;
        ConsoleLogger::info(QString("Attempt #") + QString::number(counter));
        ////////////////

        wasChanges = false;

        // fill the cells of finishes
        currentToUpdate.swap(nextToUpdate);
        nextToUpdate.clear();
        const MapPositions &finishPoses = floor->getFinishMapPositions();
        for (const Position &pos : finishPoses.getPositionList())
        {
            currentToUpdate.push_back(pos);
        }

        // iterate all current cells need to be updated
        for (const Position &currentCellPosition : currentToUpdate)
        {
            CellPtr &currectCell = floor->getCell(currentCellPosition);
            if (!currectCell) continue;
            CellAdditionalData &currentCellAdditionalData = currectCell->getAdditionalData();

            // for every neighbor
            for (const Position &relativePos : relativeNeighPositions)
            {
                // get a cell
                Position neighPos(currentCellPosition.x + relativePos.x,
                                  currentCellPosition.y + relativePos.y);

                if (!floor->isValidPosition(neighPos)) continue;

                CellPtr &neigh = floor->getCell(neighPos);
                if (!neigh) continue;

                CellAdditionalData &neighCellAdditionalData = neigh->getAdditionalData();

                // count new penalty for current cell
                Penalty newPenalty = currentCellAdditionalData.wayPenalty +
                                     neighCellAdditionalData.cellPenalty *
                                     sqrt((double)relativePos.x * (double)relativePos.x +
                                          (double)relativePos.y * (double)relativePos.y);

                // update only if the penalty is lower then the existing one
                if (neighCellAdditionalData.wayPenalty > newPenalty)
                {
                    neighCellAdditionalData.wayPenalty = newPenalty;
                    wasChanges = true;
                    nextToUpdate.push_back(neigh->getPosition());
                }
            }
        }
    }

    return true;
}

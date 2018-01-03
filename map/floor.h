#ifndef FLOOR_H
#define FLOOR_H

#include <memory>
#include <vector>
#include <deque>
#include "common/types.h"
#include <QString>
#include "cell.h"
#include "floorimage.h"
#include "human/human.h"
#include "mappositions.h"
#include "mapbarriers.h"
#include "cellmatrix.h"

class Floor
{
    Size size;
    QString name;
    FloorImagePtr floorImage;
    std::vector<HumanPtr> humanList;
    MapPositions finishPositions;
    MapBarriers mapBarriers;

    CellMatrix cellMatrix;

public:
    Floor(Size size,
          QString name,
          FloorImagePtr floorImage,
          const std::vector<HumanPtr> &humanList,
          const MapPositions &finishPositions,
          const MapBarriers &mapBarriers);

    CellPtr getCell(const Position &pos);
    CellPtr getCell(int x, int y);
    bool setCell(const Position &pos, CellPtr cell);

    FloorImagePtr getFloorImage();
    std::vector<HumanPtr> &getHumanList();

    const MapPositions &getFinishMapPositions() const;
    const MapBarriers &getMapBarriers() const;

    const Size &getSize() const;
    const QString &getName() const;

    std::shared_ptr<Floor> clone() const;

    // generate penalty way for each map cell
    void generateWayPenaltyMap();

private:
    bool isValidPosition(const Position &pos) const;

};

typedef std::shared_ptr<Floor> FloorPtr;

#endif // FLOOR_H

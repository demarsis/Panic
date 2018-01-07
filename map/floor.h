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
#include "simulation/directions.h"
#include <math.h>
#include "map/mappushes.h"

class Floor
{
    Size size;
    QString name;
    FloorImagePtr floorImage;
    std::vector<HumanPtr> humanList;
    MapPositions finishPositions;
    MapBarriers mapBarriers;
    MapPushesPtr pushesMap;

    CellMatrix cellMatrix;

public:
    Floor(Size size,
          QString name,
          FloorImagePtr floorImage,
          const std::vector<HumanPtr> &humanList,
          const MapPositions &finishPositions,
          const MapBarriers &mapBarriers);

    CellPtr &getCell(const Position &pos);
    CellPtr &getCell(int x, int y);
    CellMatrixIterator getCellIterator();
    bool setCell(const Position &pos, CellPtr cell);

    FloorImagePtr getFloorImage();
    std::vector<HumanPtr> &getHumanList();

    const MapPositions &getFinishMapPositions() const;
    const MapBarriers &getMapBarriers() const;

    const Size &getSize() const;
    const QString &getName() const;

    std::shared_ptr<Floor> clone() const;

    bool isValidPosition(const Position &pos) const;

    MapPushesPtr &getPushesMap();
};

typedef std::shared_ptr<Floor> FloorPtr;

#endif // FLOOR_H

#ifndef FLOOR_H
#define FLOOR_H

#include <memory>
#include <vector>
#include "common/types.h"
#include <QString>
#include "cell.h"
#include "floorimage.h"
#include "human/human.h"

class Floor
{
    Size size;
    QString name;
    FloorImagePtr floorImage;
    std::vector<HumanPtr> humanList;
    std::vector<std::vector<CellPtr>> cellMatrix;

public:
    Floor(Size size, QString name, FloorImagePtr floorImage, std::vector<HumanPtr> humanList);

    CellPtr getCell(const Position &pos);
    bool setCell(const Position &pos, CellPtr cell);

    const Size &getSize() const;

private:
    bool isValidPosition(const Position &pos) const;
};

typedef std::shared_ptr<Floor> FloorPtr;

#endif // FLOOR_H

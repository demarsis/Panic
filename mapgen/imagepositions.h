#ifndef STARTPOSITIONS_H
#define STARTPOSITIONS_H

#include "common/types.h"
#include <vector>
#include <QImage>
#include "map/mappositions.h"

class ImagePositions
{
    std::vector<Position> pos;

public:
    ImagePositions(const QImage &img);

    MapPositions getMapsPositions() const;
};

#endif // STARTPOSITIONS_H

#ifndef STARTPOSITIONS_H
#define STARTPOSITIONS_H

#include "common/types.h"
#include <vector>
#include <QImage>

class ImagePositions
{
    std::vector<Position> pos;

public:
    ImagePositions(const QImage &img);

    const std::vector<Position> &getPositionList() const;
};

#endif // STARTPOSITIONS_H

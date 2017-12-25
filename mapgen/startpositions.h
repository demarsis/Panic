#ifndef STARTPOSITIONS_H
#define STARTPOSITIONS_H

#include "common/types.h"
#include <vector>
#include <QImage>

class StartPositions
{
    std::vector<PositionF> pos;

public:
    StartPositions(const QImage &img);

    const std::vector<PositionF> &getStartPositionList() const;
};

#endif // STARTPOSITIONS_H

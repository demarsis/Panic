#ifndef IMAGEBARRIERS_H
#define IMAGEBARRIERS_H

#include "common/types.h"
#include <vector>
#include <QImage>
#include "map/mapbarriers.h"
#include <utility>

class ImageBarriers
{
    std::vector<std::pair<Position, BarrierType>> barriers;

public:
    ImageBarriers(const QImage &img);
    MapBarriers getMapBarriers() const;

private:
    BarrierType colorToBarrierType(QRgb pixel) const;
};

#endif // IMAGEBARRIERS_H

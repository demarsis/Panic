#include "imagebarriers.h"

ImageBarriers::ImageBarriers(const QImage &img)
    : width(img.width()),
      height(img.height())
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            BarrierType barrierType = colorToBarrierType(img.pixel(i, j));

            if (barrierType != BarrierTypeNo)
            {
                barriers.push_back(std::make_pair(Position(i, j), barrierType));
            }
        }
    }
}

MapBarriers ImageBarriers::getMapBarriers() const
{
    return MapBarriers(barriers);
}

BarrierType ImageBarriers::colorToBarrierType(QRgb pixel) const
{
    if (qAlpha(pixel) != 0)
    {
        if ((qRed(pixel)   > 100) &&
            (qGreen(pixel) < 100) &&
            (qBlue(pixel)  < 100))
        {
            return BarrierTypeCritical;
        }
        else
        {
            return BarrierTypeWall;
        }
    }
    return BarrierTypeNo;
}


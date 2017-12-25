#include "imagepositions.h"

ImagePositions::ImagePositions(const QImage &img)
{
    for (int i = 0; i < img.width(); i++)
    {
        for (int j = 0; j < img.height(); j++)
        {
            QRgb pixel = img.pixel(i, j);
            if (qAlpha(pixel) != 0)
            {
                pos.push_back(PositionF(
                                  (float)(i * CELL_MM_REAL_SIZE),
                                  (float)(j * CELL_MM_REAL_SIZE)
                                  ));
            }
        }
    }
}

const std::vector<PositionF> &ImagePositions::getStartPositionList() const
{
    return pos;
}


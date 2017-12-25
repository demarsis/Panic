#include "floorimage.h"

FloorImage::FloorImage(const QString &filename)
    : image(filename)
{
}

const QImage &FloorImage::getImage() const
{
    return image;
}

#include "floorimage.h"

FloorImage::FloorImage(const QString &filename)
    : image(filename)
{
    image = image.convertToFormat(QImage::Format_ARGB32, image.colorTable());
}

const QImage &FloorImage::getImage() const
{
    return image;
}

#include "pushesimage.h"

QImage PushesImage::pushesMapToImage(MapPushesPtr &map, const QSize &imageSize)
{
    if (!map) return QImage();
    int width = map->getSize().x;
    int height = map->getSize().y;
    if (width <= 0) return QImage();
    if (height <= 0) return QImage();

    QImage result(width, height, QImage::Format_ARGB32);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float push = map->getPush(Position(x, y));
            QColor color = Gradient::getGradientColor(push);
            color.setAlpha(150);
            result.setPixel(x, y, color.rgba());
        }
    }
    result = result.scaled(imageSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    return result;
}

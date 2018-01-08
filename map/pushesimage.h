#ifndef PUSHESIMAGE_H
#define PUSHESIMAGE_H

#include "mappushes.h"
#include <QImage>
#include "gradient.h"
#include "common/types.h"

class PushesImage
{
public:
    static QImage pushesMapToImage(MapPushesPtr &map, const QSize &imageSize);
};

#endif // PUSHESIMAGE_H

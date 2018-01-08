#ifndef PUSHESIMAGE_H
#define PUSHESIMAGE_H

#include "mappushes.h"
#include <QImage>
#include "gradient.h"

class PushesImage
{
public:
    static QImage pushesMapToImage(MapPushesPtr &map);
};

#endif // PUSHESIMAGE_H

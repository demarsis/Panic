#ifndef FLOORIMAGE_H
#define FLOORIMAGE_H

#include <memory>
#include <QString>
#include <QImage>

class FloorImage
{
    QImage image;

public:
    FloorImage(const QString &filename);

    const QImage &getImage() const;
};

typedef std::shared_ptr<FloorImage> FloorImagePtr;

#endif // FLOORIMAGE_H

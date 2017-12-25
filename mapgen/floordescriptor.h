#ifndef FLOORDESCRIPTOR_H
#define FLOORDESCRIPTOR_H

#include <QString>
#include "common/types.h"

class FloorDescriptor
{
    Size size;
    QString floorName;
    QString startPosImageFile;
    QString endPosImageFile;
    QString barriersPosImageFile;
    QString floorImageFile;

public:
    FloorDescriptor(const Size &size,
                    const QString &floorName,
                    const QString &startPosImageFile,
                    const QString &endPosImageFile,
                    const QString &barriersPosImageFile,
                    const QString &floorImageFile);

    const Size &getSize() const;
    const QString &getFloorName() const;
    const QString &getStartPosImageFile() const;
    const QString &getEndPosImageFile() const;
    const QString &getBarriersPosImageFile() const;
    const QString &getFloorImageFile() const;
};

#endif // FLOORDESCRIPTOR_H

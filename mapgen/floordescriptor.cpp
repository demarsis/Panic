#include "floordescriptor.h"

FloorDescriptor::FloorDescriptor(const Size &size,
                                 const QString &floorName,
                                 const QString &startPosImageFile,
                                 const QString &endPosImageFile,
                                 const QString &barriersPosImageFile,
                                 const QString &floorImageFile)
    : size(size),
      floorName(floorName),
      startPosImageFile(startPosImageFile),
      endPosImageFile(endPosImageFile),
      barriersPosImageFile(barriersPosImageFile),
      floorImageFile(floorImageFile)
{
}

const Size &FloorDescriptor::getSize() const
{
    return size;
}

const QString &FloorDescriptor::getFloorName() const
{
    return floorName;
}

const QString &FloorDescriptor::getStartPosImageFile() const
{
    return startPosImageFile;
}

const QString &FloorDescriptor::getEndPosImageFile() const
{
    return endPosImageFile;
}

const QString &FloorDescriptor::getBarriersPosImageFile() const
{
    return barriersPosImageFile;
}

const QString &FloorDescriptor::getFloorImageFile() const
{
    return floorImageFile;
}

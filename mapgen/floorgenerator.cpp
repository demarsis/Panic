#include "floorgenerator.h"

FloorPtr FloorGenerator::generate(const FloorDescriptor &desc)
{
    ImagePositions startPos(QImage(desc.getStartPosImageFile()));
    ImagePositions endPos(QImage(desc.getEndPosImageFile()));
    ImageBarriers barriersPos(QImage(desc.getBarriersPosImageFile()));

    HumanListGenerator humanListGenerator(startPos);

    return std::make_shared<Floor>(desc.getSize(),
                                   desc.getFloorName(),
                                   std::make_shared<FloorImage>(desc.getFloorImageFile()),
                                   humanListGenerator.getHumanList(),
                                   endPos.getMapsPositions(),
                                   barriersPos.getMapBarriers()
                                   );
}

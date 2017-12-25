#include "humanlistgenerator.h"

HumanListGenerator::HumanListGenerator(const ImagePositions &pos)
{
    for (const Position &p : pos.getMapsPositions().getPositionList())
    {
        HumanPtr human = std::make_shared<Human>(
                    PositionF(p.x, p.y),
                    30);
        humanList.push_back(human);
    }
}

const std::vector<HumanPtr> &HumanListGenerator::getHumanList() const
{
    return humanList;
}


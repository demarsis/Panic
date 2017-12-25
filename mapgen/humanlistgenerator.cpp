#include "humanlistgenerator.h"

HumanListGenerator::HumanListGenerator(const ImagePositions &pos)
{
    for (const PositionF &p : pos.getStartPositionList())
    {
        HumanPtr human = std::make_shared<Human>(p, 300);
        humanList.push_back(human);
    }
}

const std::vector<HumanPtr> &HumanListGenerator::getHumanList() const
{
    return humanList;
}


#include "humanlistgenerator.h"

HumanListGenerator::HumanListGenerator(const ImagePositions &pos)
{
    MapPositions mapPositions = pos.getMapsPositions();
    for (const Position &p : mapPositions.getPositionList())
    {
        HumanPtr human = std::make_shared<Human>(
                    PositionF(p.x, p.y),
                    30,
                    Health(),
                    GenderTypeMale,
                    AgeTypeAdult);
        humanList.push_back(human);
    }
}

const std::vector<HumanPtr> &HumanListGenerator::getHumanList() const
{
    return humanList;
}


#include "humanlistgenerator.h"

HumanListGenerator::HumanListGenerator(const ImagePositions &pos,
                                       const MapCharacteristics &mapChar)
{
    MapPositions mapPositions = pos.getMapsPositions();
    for (const Position &p : mapPositions.getPositionList())
    {
        AgeType age = mapChar.ageProbabilityRelation().generate();
        GenderType gender = mapChar.genderProbabilityRelation().generate();

        HumanPtr human = std::make_shared<Human>(
                    PositionF(p.x, p.y),
                    50,
                    Health(),
                    gender,
                    age);
        humanList.push_back(human);
    }
}

const std::vector<HumanPtr> &HumanListGenerator::getHumanList() const
{
    return humanList;
}


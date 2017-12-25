#include "humanlistgenerator.h"

HumanListGenerator::HumanListGenerator(const ImagePositions &pos)
{
    for (const Position &p : pos.getPositionList())
    {
        HumanPtr human = std::make_shared<Human>(
                    PositionF(p.x * CELL_MM_REAL_SIZE, p.y * CELL_MM_REAL_SIZE),
                    300);
        humanList.push_back(human);
    }
}

const std::vector<HumanPtr> &HumanListGenerator::getHumanList() const
{
    return humanList;
}


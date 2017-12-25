#ifndef HUMANLISTGENERATOR_H
#define HUMANLISTGENERATOR_H

#include "startpositions.h"
#include <vector>
#include "human/human.h"
#include <memory>

class HumanListGenerator
{
    std::vector<HumanPtr> humanList;

public:
    HumanListGenerator(const StartPositions &pos);
    const std::vector<HumanPtr> &getHumanList() const;
};

#endif // HUMANLISTGENERATOR_H

#ifndef HUMANLISTGENERATOR_H
#define HUMANLISTGENERATOR_H

#include "imagepositions.h"
#include <vector>
#include "human/human.h"
#include "human/age.h"
#include "human/gender.h"
#include <memory>
#include "common/consolelogger.h"
#include "probability/probabilityrelation.h"
#include "mapcharacteristics.h"

class HumanListGenerator
{
    std::vector<HumanPtr> humanList;

public:
    HumanListGenerator(const ImagePositions &pos,
                       const MapCharacteristics &mapChar);
    const std::vector<HumanPtr> &getHumanList() const;
};

#endif // HUMANLISTGENERATOR_H

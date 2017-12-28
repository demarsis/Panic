#ifndef MAPCHARACTERISTICS_H
#define MAPCHARACTERISTICS_H

#include "probability/probabilityrelation.h"
#include "human/age.h"
#include "human/gender.h"

class MapCharacteristics
{
    ProbabilityRelation<AgeType> ageProbRelation;
    ProbabilityRelation<GenderType> genderProbRelation;

public:
    MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                       const ProbabilityRelation<GenderType> &genderProbRelation);

    const ProbabilityRelation<AgeType> &ageProbabilityRelation() const;
    const ProbabilityRelation<GenderType> &genderProbabilityRelation() const;
};

#endif // MAPCHARACTERISTICS_H

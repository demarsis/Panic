#ifndef MAPCHARACTERISTICS_H
#define MAPCHARACTERISTICS_H

#include "probability/probabilityrelation.h"
#include "human/age.h"
#include "human/gender.h"

class MapCharacteristics
{
    ProbabilityRelation<AgeType> ageProbRelation;
    ProbabilityRelation<GenderType> genderProbRelation;
    ProbabilityRelation<bool> creationProbRelation;

public:
    MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                       const ProbabilityRelation<GenderType> &genderProbRelation,
                       const ProbabilityRelation<bool> &creationProbRelation);

    const ProbabilityRelation<AgeType> &ageProbabilityRelation() const;
    const ProbabilityRelation<GenderType> &genderProbabilityRelation() const;
    const ProbabilityRelation<bool> &creationProbabilityRelation() const;
};

#endif // MAPCHARACTERISTICS_H

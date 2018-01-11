#ifndef MAPCHARACTERISTICS_H
#define MAPCHARACTERISTICS_H

#include "probability/probabilityrelation.h"
#include "human/age.h"
#include "human/gender.h"
#include "human/panic.h"

class MapCharacteristics
{
    ProbabilityRelation<AgeType> ageProbRelation;
    ProbabilityRelation<GenderType> genderProbRelation;
    ProbabilityRelation<bool> creationProbRelation;
    ProbabilityRelation<PanicType> panicProbRelation;

public:
    MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                       const ProbabilityRelation<GenderType> &genderProbRelation,
                       const ProbabilityRelation<bool> &creationProbRelation,
                       const ProbabilityRelation<PanicType> &panicProbRelation);

    const ProbabilityRelation<AgeType> &ageProbabilityRelation() const;
    const ProbabilityRelation<GenderType> &genderProbabilityRelation() const;
    const ProbabilityRelation<bool> &creationProbabilityRelation() const;
    const ProbabilityRelation<PanicType> &panicProbabilityRelation() const;
};

#endif // MAPCHARACTERISTICS_H

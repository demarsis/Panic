#include "mapcharacteristics.h"

MapCharacteristics::MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                                       const ProbabilityRelation<GenderType> &genderProbRelation)
    : ageProbRelation(ageProbRelation),
      genderProbRelation(genderProbRelation)
{
}

const ProbabilityRelation<AgeType> &MapCharacteristics::ageProbabilityRelation() const
{
    return ageProbRelation;
}

const ProbabilityRelation<GenderType> &MapCharacteristics::genderProbabilityRelation() const
{
    return genderProbRelation;
}


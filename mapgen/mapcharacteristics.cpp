#include "mapcharacteristics.h"

MapCharacteristics::MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                                       const ProbabilityRelation<GenderType> &genderProbRelation,
                                       const ProbabilityRelation<bool> &creationProbRelation)
    : ageProbRelation(ageProbRelation),
      genderProbRelation(genderProbRelation),
      creationProbRelation(creationProbRelation)
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

const ProbabilityRelation<bool> &MapCharacteristics::creationProbabilityRelation() const
{
    return creationProbRelation;
}


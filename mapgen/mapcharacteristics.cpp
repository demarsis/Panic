#include "mapcharacteristics.h"

MapCharacteristics::MapCharacteristics(const ProbabilityRelation<AgeType> &ageProbRelation,
                                       const ProbabilityRelation<GenderType> &genderProbRelation,
                                       const ProbabilityRelation<bool> &creationProbRelation,
                                       const ProbabilityRelation<PanicType> &panicProbRelation)
    : ageProbRelation(ageProbRelation),
      genderProbRelation(genderProbRelation),
      creationProbRelation(creationProbRelation),
      panicProbRelation(panicProbRelation)
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

const ProbabilityRelation<PanicType> &MapCharacteristics::panicProbabilityRelation() const
{
    return panicProbRelation;
}


#include "humaninfluence.h"

HumanInfluence::HumanInfluence(float diameterCoeff)
    : diameterCoeff(diameterCoeff)
{
}

float HumanInfluence::getDiameterCoeff() const
{
    return diameterCoeff;
}


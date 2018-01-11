#include "humaninfluence.h"

HumanInfluence::HumanInfluence(float diameterCoeff, float speedCoeff)
    : diameterCoeff(diameterCoeff),
      speedCoeff(speedCoeff)
{
}

float HumanInfluence::getDiameterCoeff() const
{
    return diameterCoeff;
}

float HumanInfluence::getSpeedCoeff() const
{
    return speedCoeff;
}


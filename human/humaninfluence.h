#ifndef HUMANINFLUENCE_H
#define HUMANINFLUENCE_H


class HumanInfluence
{
    float diameterCoeff;
    float speedCoeff;

public:
    HumanInfluence(float diameterCoeff, float speedCoeff);

    float getDiameterCoeff() const;
    float getSpeedCoeff() const;
};

#endif // HUMANINFLUENCE_H

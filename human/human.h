#ifndef HUMAN_H
#define HUMAN_H

#include <memory>
#include "common/types.h"
#include "health.h"
#include "gender.h"
#include "age.h"
#include "panic.h"
#include "simulation/vector.h"
#include "probability/probability.h"
#include "common/defines.h"

struct HumanAdditionalData
{
    Vector intentionVector;
    bool movementDecision;
    std::vector<Vector> pushes;
};

class Human
{
    PositionF pos;
    Diameter diameter;
    Health health;
    GenderPtr gender;
    AgePtr age;
    PanicPtr panic;
    float speedCoeff;
    HumanAdditionalData additionalData;

public:
    Human(PositionF pos, Diameter diameter, Health health, GenderType genderType, AgeType ageType, PanicType panicType);

    const PositionF &getPosition() const;
    void setPosition(const PositionF &pos);

    Diameter getDiameter() const;
    const Health &getHealth() const;

    GenderType getGenderType() const;
    AgeType getAgeType() const;
    PanicType getPanicType() const;

    std::shared_ptr<Human> clone() const;

    HumanAdditionalData &getAdditionalData();
    float getSpeedCoeff() const;
};

typedef std::shared_ptr<Human> HumanPtr;

#endif // HUMAN_H

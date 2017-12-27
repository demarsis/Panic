#ifndef HUMAN_H
#define HUMAN_H

#include <memory>
#include "common/types.h"
#include "health.h"
#include "gender.h"
#include "age.h"

class Human
{
    PositionF pos;
    Diameter diameter;
    Health health;
    GenderPtr gender;
    AgePtr age;

public:
    Human(PositionF pos, Diameter diameter, Health health, GenderType genderType, AgeType ageType);

    const PositionF &getPosition() const;
    void setPosition(const PositionF &pos);

    Diameter getDiameter() const;
    const Health &getHealth() const;

    GenderType getGenderType() const;
    AgeType getAgeType() const;

    std::shared_ptr<Human> clone() const;
};

typedef std::shared_ptr<Human> HumanPtr;

#endif // HUMAN_H

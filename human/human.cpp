#include "human.h"

Human::Human(PositionF pos, Diameter diameter, Health health, GenderType genderType, AgeType ageType, PanicType panicType)
    : pos(pos),
      diameter(diameter),
      health(health),
      gender(GenderFactory::generateGender(genderType)),
      age(AgeFactory::generateAge(ageType)),
      panic(PanicFactory::generatePanic(panicType)),
      speedCoeff(1)
{
    // diameter influence
    this->diameter *= gender->getInfluence().getDiameterCoeff();
    this->diameter *= age->getInfluence().getDiameterCoeff();

    // speed influence
    this->speedCoeff *= gender->getInfluence().getSpeedCoeff();
    this->speedCoeff *= age->getInfluence().getSpeedCoeff();
}

const PositionF &Human::getPosition() const
{
    return pos;
}

void Human::setPosition(const PositionF &pos)
{
    this->pos = pos;
}

Diameter Human::getDiameter() const
{
    return diameter;
}

const Health &Human::getHealth() const
{
    return health;
}

GenderType Human::getGenderType() const
{
    return gender->type();
}

AgeType Human::getAgeType() const
{
    return age->type();
}

PanicType Human::getPanicType() const
{
    return panic->type();
}

std::shared_ptr<Human> Human::clone() const
{
    return std::make_shared<Human>(pos, diameter, health,
                                   getGenderType(),
                                   getAgeType(),
                                   getPanicType());
}

HumanAdditionalData &Human::getAdditionalData()
{
    return additionalData;
}

float Human::getSpeedCoeff() const
{
    return speedCoeff;
}

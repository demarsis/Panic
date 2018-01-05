#include "human.h"

Human::Human(PositionF pos, Diameter diameter, Health health, GenderType genderType, AgeType ageType)
    : pos(pos),
      diameter(diameter),
      health(health),
      gender(GenderFactory::generateGender(genderType)),
      age(AgeFactory::generateAge(ageType))
{
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

std::shared_ptr<Human> Human::clone() const
{
    return std::make_shared<Human>(pos, diameter, health,
                                   getGenderType(),
                                   getAgeType()
                                   );
}

HumanAdditionalData &Human::getAdditionalData()
{
    return additionalData;
}

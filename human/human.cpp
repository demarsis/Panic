#include "human.h"

Human::Human(PositionF pos, Diameter diameter, Health health, GenderType genderType)
    : pos(pos),
      diameter(diameter),
      health(health),
      gender(GenderFactory::generateGender(genderType))
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

std::shared_ptr<Human> Human::clone() const
{
    return std::make_shared<Human>(pos, diameter, health,
                                   getGenderType());
}

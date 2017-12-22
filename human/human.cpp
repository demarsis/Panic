#include "human.h"

Human::Human(PositionF pos, Diameter diameter)
    : pos(pos),
      diameter(diameter)
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

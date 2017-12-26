#ifndef HUMAN_H
#define HUMAN_H

#include <memory>
#include "common/types.h"
#include "health.h"

class Human
{
    PositionF pos;
    Diameter diameter;
    Health health;

public:
    Human(PositionF pos, Diameter diameter, Health health);

    const PositionF &getPosition() const;
    void setPosition(const PositionF &pos);

    Diameter getDiameter() const;
    const Health &getHealth() const;

    std::shared_ptr<Human> clone() const;
};

typedef std::shared_ptr<Human> HumanPtr;

#endif // HUMAN_H

#ifndef HUMAN_H
#define HUMAN_H

#include <memory>
#include "common/types.h"

class Human
{
public:
    Human();
};

typedef std::shared_ptr<Human> HumanPtr;

#endif // HUMAN_H

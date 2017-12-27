#include "age.h"

Age::Age(const HumanInfluence &influence)
    : influence(influence)
{
}

const HumanInfluence &Age::getInfluence() const
{
    return influence;
}

//############################

AgeChild::AgeChild()
    : Age(HumanInfluence())
{
}

QString AgeChild::toString() const
{
    return "Child";
}

AgeType AgeChild::type() const
{
    return AgeTypeChild;
}

//############################

AgeAdult::AgeAdult()
    : Age(HumanInfluence())
{
}

QString AgeAdult::toString() const
{
    return "Adult";
}

AgeType AgeAdult::type() const
{
    return AgeTypeAdult;
}

//############################

AgeElderly::AgeElderly()
    : Age(HumanInfluence())
{
}

QString AgeElderly::toString() const
{
    return "Elderly";
}

AgeType AgeElderly::type() const
{
    return AgeTypeElderly;
}

//############################

AgePtr AgeFactory::generateAge(AgeType type)
{
    switch (type)
    {
    case AgeTypeChild:
        return std::make_shared<AgeChild>();
    case AgeTypeAdult:
        return std::make_shared<AgeAdult>();
    case AgeTypeElderly:
        return std::make_shared<AgeElderly>();
    }

    return std::make_shared<AgeChild>();
}

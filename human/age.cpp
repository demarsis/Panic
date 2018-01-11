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
    : Age(HumanInfluence(0.9f, 0.8f))
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
    : Age(HumanInfluence(1.0f, 1.0f))
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
    : Age(HumanInfluence(0.95f, 0.6f))
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

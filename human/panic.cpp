#include "panic.h"

Panic::Panic(const HumanInfluence &influence)
    : influence(influence)
{
}

const HumanInfluence &Panic::getInfluence() const
{
    return influence;
}

//############################

PanicNo::PanicNo()
    : Panic(HumanInfluence(1.0f, 1.0f))
{
}

QString PanicNo::toString() const
{
    return "No panic";
}

PanicType PanicNo::type() const
{
    return PanicTypeNo;
}

//############################

PanicMinor::PanicMinor()
    : Panic(HumanInfluence(1.0f, 1.5f))
{
}

QString PanicMinor::toString() const
{
    return "A little panic";
}

PanicType PanicMinor::type() const
{
    return PanicTypeMinor;
}

//############################


PanicMajor::PanicMajor()
    : Panic(HumanInfluence(1.0f, 2.0f))
{
}

QString PanicMajor::toString() const
{
    return "Panic";
}

PanicType PanicMajor::type() const
{
    return PanicTypeMajor;
}

//############################


PanicPtr PanicFactory::generatePanic(PanicType type)
{
    switch (type)
    {
    case PanicTypeNo:
        return std::make_shared<PanicNo>();
    case PanicTypeMinor:
        return std::make_shared<PanicMinor>();
    case PanicTypeMajor:
        return std::make_shared<PanicMajor>();
    }
    return std::make_shared<PanicNo>();
}

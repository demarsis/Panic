#include "gender.h"

Gender::Gender(const HumanInfluence &influence)
    : influence(influence)
{
}

const HumanInfluence &Gender::getInfluence() const
{
    return influence;
}

//############################

GenderMale::GenderMale()
    : Gender(HumanInfluence(1.0f, 1.0f))
{
}

QString GenderMale::toString() const
{
    return "Male";
}

GenderType GenderMale::type() const
{
    return GenderTypeMale;
}

//############################

GenderFemale::GenderFemale()
    : Gender(HumanInfluence(0.95f, 0.95f))
{
}

QString GenderFemale::toString() const
{
    return "Female";
}

GenderType GenderFemale::type() const
{
    return GenderTypeFemale;
}

//############################

GenderPtr GenderFactory::generateGender(GenderType type)
{
    switch (type)
    {
    case GenderTypeMale:
        return std::make_shared<GenderMale>();
    case GenderTypeFemale:
        return std::make_shared<GenderFemale>();
    }

    // default
    return std::make_shared<GenderMale>();
}

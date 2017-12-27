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
    : Gender(HumanInfluence())
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
    : Gender(HumanInfluence())
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

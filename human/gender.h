#ifndef GENDER_H
#define GENDER_H

#include <memory>
#include "QString"
#include "humaninfluence.h"

enum GenderType
{
    GenderTypeMale,
    GenderTypeFemale
};

class Gender
{
    HumanInfluence influence;

public:
    Gender(const HumanInfluence &influence);
    const HumanInfluence &getInfluence() const;
    virtual QString toString() const = 0;
    virtual GenderType type() const = 0;
};

typedef std::shared_ptr<Gender> GenderPtr;

//############################

class GenderMale : public Gender
{
public:
    GenderMale();
    virtual QString toString() const;
    virtual GenderType type() const;
};

//############################

class GenderFemale : public Gender
{
public:
    GenderFemale();
    virtual QString toString() const;
    virtual GenderType type() const;
};

//############################

class GenderFactory
{
public:
    static GenderPtr generateGender(GenderType type);
};


#endif // GENDER_H

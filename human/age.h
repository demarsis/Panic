#ifndef AGE_H
#define AGE_H

#include <memory>
#include "QString"
#include "humaninfluence.h"

enum AgeType
{
    AgeTypeChild,
    AgeTypeAdult,
    AgeTypeElderly
};

class Age
{
    HumanInfluence influence;

public:
    Age(const HumanInfluence &influence);
    const HumanInfluence &getInfluence() const;
    virtual QString toString() const = 0;
    virtual AgeType type() const = 0;
};

typedef std::shared_ptr<Age> AgePtr;

//############################

class AgeChild : public Age
{
public:
    AgeChild();
    virtual QString toString() const;
    virtual AgeType type() const;
};

//############################

class AgeAdult : public Age
{
public:
    AgeAdult();
    virtual QString toString() const;
    virtual AgeType type() const;
};

//############################

class AgeElderly : public Age
{
public:
    AgeElderly();
    virtual QString toString() const;
    virtual AgeType type() const;
};

//############################

class AgeFactory
{
public:
    static AgePtr generateAge(AgeType type);
};

#endif // AGE_H

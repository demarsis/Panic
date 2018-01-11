#ifndef PANIC_H
#define PANIC_H

#include <memory>
#include "QString"
#include "humaninfluence.h"

enum PanicType
{
    PanicTypeNo,
    PanicTypeMinor,
    PanicTypeMajor
};

class Panic
{
    HumanInfluence influence;

public:
    Panic(const HumanInfluence &influence);
    const HumanInfluence &getInfluence() const;
    virtual QString toString() const = 0;
    virtual PanicType type() const = 0;
};

typedef std::shared_ptr<Panic> PanicPtr;

//############################

class PanicNo : public Panic
{
public:
    PanicNo();
    virtual QString toString() const;
    virtual PanicType type() const;
};
//############################

class PanicMinor : public Panic
{
public:
    PanicMinor();
    virtual QString toString() const;
    virtual PanicType type() const;
};

//############################

class PanicMajor : public Panic
{
public:
    PanicMajor();
    virtual QString toString() const;
    virtual PanicType type() const;
};

//############################

class PanicFactory
{
public:
    static PanicPtr generatePanic(PanicType type);
};

#endif // PANIC_H

#ifndef HEALTH_H
#define HEALTH_H

#include "common/types.h"

enum HealthStatus
{
    Ok,
    MinorDamage,
    MajorDamage,
    Dead
};

class Health
{
    float health; // 0..100

public:
    Health();

    HealthStatus getStatus() const;
    bool isDead() const;

    void applyMinDamage();
};

#endif // HEALTH_H

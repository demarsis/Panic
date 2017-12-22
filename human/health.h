#ifndef HEALTH_H
#define HEALTH_H

enum HealthStatus
{
    Ok,
    MinorDamage,
    MajorDamage,
    Dead
};

class Health
{
    float health;

public:
    Health();

    HealthStatus getStatus() const;
    bool isDead() const;
};

#endif // HEALTH_H

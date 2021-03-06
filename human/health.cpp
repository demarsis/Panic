#include "health.h"

Health::Health()
    : health(100)
{
}

HealthStatus Health::getStatus() const
{
    if (health > 80) return HealthStatus::Ok;
    if (health > 50) return HealthStatus::MinorDamage;
    if (health >= 1) return HealthStatus::MajorDamage;
    return HealthStatus::Dead;
}

bool Health::isDead() const
{
    return getStatus() == HealthStatus::Dead;
}

void Health::applyMinDamage()
{
    health =- 0.1f;
}


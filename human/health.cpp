#include "health.h"

Health::Health()
{

}

HealthStatus Health::getStatus() const
{
    return HealthStatus::Dead;
}

bool Health::isDead() const
{
    return getStatus() == HealthStatus::Dead;
}


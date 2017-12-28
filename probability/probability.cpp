#include "probability.h"

Probability::Probability()
{
    srand(time(0));
}

Probability &Probability::instance()
{
    static Probability prob;
    return prob;
}

int Probability::random(int limit)
{
    return rand() % limit;
}


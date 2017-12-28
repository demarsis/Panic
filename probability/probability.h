#ifndef PROBABILITY_H
#define PROBABILITY_H

#include <time.h>
#include <cstdlib>

class Probability
{
public:
    static Probability &instance();
    int random(int limit);

private:
    Probability();
};

#endif // PROBABILITY_H

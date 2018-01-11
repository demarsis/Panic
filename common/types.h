#ifndef TYPES_H
#define TYPES_H

#include <limits>

typedef float Penalty;

#define PENALTY_FREE_CELL           ((float)1)
#define PENALTY_CRITICAL_CELL       ((float)1000)
#define PENALTY_WALL_CELL           ((float)1000)
#define PENALTY_MAX                 ((float)1000000)
#define PENALTY_ZERO                ((float)0)

typedef float Diameter;

#define HUMAN_INTENTION_SPEED_COEFF           ((float)0.15f)
#define HUMAN_PUSH_COEFF                      ((float)0.7f)

struct Position
{
    int x, y;
    Position(int x, int y) : x(x), y(y) {}
};

struct PositionF
{
    double x, y;
    PositionF(float x, float y) : x(x), y(y) {}
};

struct Size
{
    int x, y;
    Size(int x, int y) : x(x), y(y) {}
};


#endif // TYPES_H

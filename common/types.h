#ifndef TYPES_H
#define TYPES_H

typedef float CellPenalty;
typedef float CellCost;
typedef float Diameter;

#define PENALTY_WALL              (double(10000))
#define PENALTY_EMERGENCY         (double(100))
#define PENALTY_HUMAN             (double(1))

#define CELL_MM_REAL_SIZE         (long(10))

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

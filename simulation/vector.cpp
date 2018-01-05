#include "vector.h"

Vector::Vector()
    : x(0), y(0)
{
}

Vector::Vector(float x, float y)
    : x(x), y(y)
{
}

float Vector::getX() const
{
    return x;
}

float Vector::getY() const
{
    return y;
}

Vector Vector::operator =(const Vector &obj)
{
    x = obj.x;
    y = obj.y;
    return *this;
}

Vector Vector::operator +(const Vector &obj) const
{
    return Vector(x + obj.x,
                  y + obj.y);
}

Vector Vector::operator -(const Vector &obj) const
{
    return Vector(x - obj.x,
                  y - obj.y);
}

Vector Vector::operator *(float mult) const
{
    return Vector(x * mult, y * mult);
}

Vector Vector::operator *=(float mult)
{
    x *= mult;
    y *= mult;
    return *this;
}

Vector Vector::operator -() const
{
    return Vector(-x, -y);
}



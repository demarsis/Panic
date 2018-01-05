#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    float x, y;

public:
    Vector();
    Vector(float x, float y);

    float getX() const;
    float getY() const;

    Vector operator = (const Vector &obj);
    Vector operator + (const Vector &obj) const;
    Vector operator - (const Vector &obj) const;
    Vector operator * (float mult) const;

    Vector operator *= (float mult);

    Vector operator -() const;
};

#endif // VECTOR_H

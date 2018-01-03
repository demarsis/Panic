#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    float x, y;

public:
    Vector();
    Vector(float x, float y);

    Vector operator = (const Vector &obj);
    Vector operator + (const Vector &obj) const;
    Vector operator - (const Vector &obj) const;
    Vector operator * (float mult) const;
};

#endif // VECTOR_H

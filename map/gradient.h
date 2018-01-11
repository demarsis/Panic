#ifndef GRADIENT_H
#define GRADIENT_H

#include <QColor>

#define MAX_GRADIENT_VALUE      (float(10))

class Gradient
{
public:
    static QColor getGradientColor(float value);
};

#endif // GRADIENT_H

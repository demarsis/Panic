#include "gradient.h"

QColor Gradient::getGradientColor(float value)
{
    // range [0..100]
    if (value < 0) value = 0;
    if (value > MAX_GRADIENT_VALUE) value = MAX_GRADIENT_VALUE;

    // inverse
    value = MAX_GRADIENT_VALUE - value;

    // convert to hsv
    return QColor::fromHsv((int)(value), 255, 255);
}

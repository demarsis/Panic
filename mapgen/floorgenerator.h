#ifndef FLOORGENERATOR_H
#define FLOORGENERATOR_H

#include "floordescriptor.h"
#include "map/floor.h"
#include "humanlistgenerator.h"
#include "imagepositions.h"
#include "imagebarriers.h"
#include "map/mappositions.h"
#include "map/mapbarriers.h"

class FloorGenerator
{
public:
    static FloorPtr generate(const FloorDescriptor &desc);
};

#endif // FLOORGENERATOR_H

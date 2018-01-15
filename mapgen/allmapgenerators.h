#ifndef ALLMAPGENERATORS_H
#define ALLMAPGENERATORS_H

#include <vector>
#include "mapgeneratorcafe.h"
#include "mapgeneratortheaterblocked.h"
#include "mapgeneratortheater.h"
#include "mapgeneratortestfindexit.h"

class AllMapGenerators
{
public:
    static std::vector<MapGeneratorPtr> get();
};

#endif // ALLMAPGENERATORS_H

#include "allmapgenerators.h"

std::vector<MapGeneratorPtr> AllMapGenerators::get()
{
    std::vector<MapGeneratorPtr> result;
    result.push_back(std::make_shared<MapGeneratorTest1>());
    result.push_back(std::make_shared<MapGeneratorCafe>());    
    return result;
}

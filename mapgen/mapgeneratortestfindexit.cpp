#include "mapgeneratortestfindexit.h"

MapPtr MapGeneratorTestFindExit::generate(const MapCharacteristics &mapChar) const
{
    Floors floors;
    FloorDescriptor groundFloorDescriptor(
                Size(40, 40),
                "Ground Floor",
                "maps\\test_findexit\\starts.png",
                "maps\\test_findexit\\finishes.png",
                "maps\\test_findexit\\barriers.png",
                "maps\\test_findexit\\image.png"
                );

    floors.push_back(FloorGenerator::generate(groundFloorDescriptor, mapChar));
    return std::make_shared<Map>(name(), floors);
}

QString MapGeneratorTestFindExit::name() const
{
    return "Test: find exit";
}

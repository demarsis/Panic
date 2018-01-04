#include "mapgeneratortest1.h"

MapPtr MapGeneratorTest1::generate(const MapCharacteristics &mapChar) const
{
    Floors floors;
    FloorDescriptor groundFloorDescriptor(
                Size(5, 5),
                "Ground Floor",
                "maps\\test1\\starts.png",
                "maps\\test1\\finishes.png",
                "maps\\test1\\barriers.png",
                "maps\\test1\\image.png"
                );

    floors.push_back(FloorGenerator::generate(groundFloorDescriptor, mapChar));
    return std::make_shared<Map>(name(), floors);
}

QString MapGeneratorTest1::name() const
{
    return "Test1 5x5";
}

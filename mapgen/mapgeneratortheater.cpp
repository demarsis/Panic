#include "mapgeneratortheater.h"

MapPtr MapGeneratorTheater::generate(const MapCharacteristics &mapChar) const
{
    Floors floors;
    FloorDescriptor groundFloorDescriptor(
                Size(512, 340),
                "Афмитеатр",
                "maps\\theater\\floor1\\starts.png",
                "maps\\theater\\floor1\\finishes.png",
                "maps\\theater\\floor1\\barriers.png",
                "maps\\theater\\floor1\\image.png"
                );

    floors.push_back(FloorGenerator::generate(groundFloorDescriptor, mapChar));
    return std::make_shared<Map>(name(), floors);
}

QString MapGeneratorTheater::name() const
{
    return "Theater";
}

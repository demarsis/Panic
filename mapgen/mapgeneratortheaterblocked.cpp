#include "mapgeneratortheaterblocked.h"

MapPtr MapGeneratorTheaterBlocked::generate(const MapCharacteristics &mapChar) const
{
    Floors floors;
    FloorDescriptor groundFloorDescriptor(
                Size(512, 340),
                "Афмитеатр",
                "maps\\theater-blocked\\floor1\\starts.png",
                "maps\\theater-blocked\\floor1\\finishes.png",
                "maps\\theater-blocked\\floor1\\barriers.png",
                "maps\\theater-blocked\\floor1\\image.png"
                );

    floors.push_back(FloorGenerator::generate(groundFloorDescriptor, mapChar));
    return std::make_shared<Map>(name(), floors);
}

QString MapGeneratorTheaterBlocked::name() const
{
    return "Theater (blocked)";
}

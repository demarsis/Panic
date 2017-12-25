#include "mapgeneratorcafe.h"


MapPtr MapGeneratorCafe::generate() const
{
    Floors floors;
    FloorDescriptor groundFloorDescriptor(
                Size(200, 200),
                "Ground Floor",
                "maps\\cafe\\floor1\\starts.png",
                "maps\\cafe\\floor1\\finishes.png",
                "maps\\cafe\\floor1\\barriers.png",
                "maps\\cafe\\floor1\\image.png"
                );

    floors.push_back(FloorGenerator::generate(groundFloorDescriptor));
    return std::make_shared<Map>("Cafe", floors);
}

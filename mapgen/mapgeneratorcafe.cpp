#include "mapgeneratorcafe.h"


MapPtr MapGeneratorCafe::generate() const
{
    Floors floors;

    // ground floor
    std::vector<HumanPtr> humanList;
    floors.push_back(std::make_shared<Floor>(Size(200, 200),
                                             "Ground Floor",
                                             std::make_shared<FloorImage>("maps\\cafe\\floor1\\image.png"),
                                             humanList
                                             ));

    return std::make_shared<Map>("Cafe", floors);
}

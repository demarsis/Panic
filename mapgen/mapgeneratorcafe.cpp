#include "mapgeneratorcafe.h"


MapPtr MapGeneratorCafe::generate() const
{
    Floors floors;

    //########################
    //# ground floor
    //########################

    StartPositions startPos(QImage("maps\\cafe\\floor1\\starts.png"));
    HumanListGenerator humanListGenerator(startPos);

    floors.push_back(std::make_shared<Floor>(Size(200, 200),
                                             "Ground Floor",
                                             std::make_shared<FloorImage>("maps\\cafe\\floor1\\image.png"),
                                             humanListGenerator.getHumanList()
                                             ));


    return std::make_shared<Map>("Cafe", floors);
}

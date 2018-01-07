#include "simulator.h"

Simulator::Simulator(SimulatorWidget &openGLWidget, int simulationSpeed, MapPtr map)
    : openGLWidget(openGLWidget),
      simulationSpeed(simulationSpeed)
{
    if (map)
    {
        this->map = map->clone();

        // generate way penalty for cell matrix for each floor
        for (FloorPtr floor : this->map->getFloors())
        {
            PenaltyWayBuilder::generate(floor);
        }
    }
    stopwatch = std::make_shared<Stopwatch>(simulationSpeed);

    timer.setInterval(17);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

MapPtr Simulator::getMap()
{
    return map;
}

StopwatchPtr Simulator::getStopwatch()
{
    return stopwatch;
}

void Simulator::start()
{
    stopwatch->start();
    timer.start();
}

void Simulator::pause()
{
    stopwatch->pause();
    timer.stop();
}

void Simulator::setSpeed(int simulationSpeed)
{
    this->simulationSpeed = simulationSpeed;
    if (stopwatch) stopwatch->setSpeedCoeff(simulationSpeed);
}

void Simulator::onTimer()
{
    for (int i = 0; i < simulationSpeed; i++)
    {
        updateHumanVectors();
    }

    openGLWidget.update();
}

void Simulator::updateHumanVectors()
{
    if (!map) return;

    // disapeare
    disapeareHumans();

    // make intentions vectors
    for (FloorPtr &floor : map->getFloors())
    {
        if (!floor) continue;
        for (HumanPtr &human : floor->getHumanList())
        {
            if (!human) continue;

            // get movement vector
            Vector vec = HumanVector::getIntentionVector(human, floor);

            // set current vector
            HumanAdditionalData &humanAddData = human->getAdditionalData();
            humanAddData.intentionVector = vec;
            humanAddData.movementDecision = false;

            // clear pushes
            humanAddData.pushes.clear();
        }
    }

    ProbabilityRelation<float> moveProbabylity;
    moveProbabylity.addProbs(1, 20);
    moveProbabylity.addProbs(0, 80);

    // check intersections
    for (FloorPtr &floor : map->getFloors())
    {
        if (!floor) continue;
        std::vector<HumanPtr> &humanList = floor->getHumanList();
        MapPushesPtr &pushesMap = floor->getPushesMap();

        for (size_t i = 0; i < humanList.size(); i++)
        {
            HumanPtr &human = humanList[i];
            if (!human) continue;
            HumanAdditionalData &humanAddData = human->getAdditionalData();

            for (size_t j = i + 1; j < humanList.size(); j++)
            {
                HumanPtr &other = humanList[j];
                if (!other) continue;
                HumanAdditionalData &otherAddData = other->getAdditionalData();

                // have intersection?
                bool intersection = HumanVector::isNewPositionIntersectedWithOther(human, humanAddData.intentionVector, other);

                if (intersection)
                {
                    // one moves; other stands
                    if (!humanAddData.movementDecision)
                    {
                        humanAddData.movementDecision = true;
                        otherAddData.intentionVector *= moveProbabylity.generate();
                    }
                    if (!otherAddData.movementDecision)
                    {
                        otherAddData.movementDecision = true;
                        otherAddData.intentionVector *= moveProbabylity.generate();
                    }
                }

                // reciprocal pushes
                if (intersection)
                {
                    Vector humanPush = HumanVector::getPushesVector(human, other);
                    humanAddData.pushes.push_back(humanPush);
                    otherAddData.pushes.push_back(-humanPush);

                    // notice pushes into pushes map
                    if (pushesMap)
                    {
                        std::vector<CellPtr> cellsHuman = HumanVector::getHumanCells(human, floor);
                        std::vector<CellPtr> cellsOther = HumanVector::getHumanCells(other, floor);

                        for (const CellPtr &cell : cellsHuman)
                        {
                            if (!cell) continue;
                            pushesMap->addPush(cell->getPosition(), humanPush);
                        }
                        for (const CellPtr &cell : cellsOther)
                        {
                            if (!cell) continue;
                            pushesMap->addPush(cell->getPosition(), humanPush);
                        }
                    }
                }
            }
        }
    }

    // update human's positions
    for (FloorPtr &floor : map->getFloors())
    {
        if (!floor) continue;
        for (HumanPtr &human : floor->getHumanList())
        {
            if (!human) continue;
            HumanAdditionalData &humanAddData = human->getAdditionalData();

            // get movement vector
            Vector vec = human->getAdditionalData().intentionVector;
            for (const Vector &push : humanAddData.pushes)
            {
                vec = vec + push;
            }

            // get current position
            const PositionF &pos = human->getPosition();

            // set new position
            human->setPosition(PositionF(vec.getX() + pos.x, vec.getY() + pos.y));
        }
    }
}

void Simulator::disapeareHumans()
{
    if (!map) return;

    // make intentions vectors
    for (FloorPtr &floor : map->getFloors())
    {
        if (!floor) continue;
        std::vector<HumanPtr> &humanList = floor->getHumanList();
        std::vector<HumanPtr>::iterator it = humanList.begin();
        while (it != humanList.end())
        {
            HumanPtr &human = *it;
            if (!human)
            {
                it++;
                continue;
            }

            const PositionF &humanPosF = human->getPosition();
            Position pos(humanPosF.x, humanPosF.y);

            if (!floor->isValidPosition(pos))
            {
                it++;
                continue;
            }

            const CellPtr &cell = floor->getCell(pos);
            if (!cell)
            {
                it++;
                continue;
            }

            if (cell->getExit().isExit())
            {
                finishedHumanList.push_back(human);
                it = humanList.erase(it);
                continue;
            }

            it++;
        }
    }
}


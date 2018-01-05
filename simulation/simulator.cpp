#include "simulator.h"

Simulator::Simulator(SimulatorWidget &openGLWidget, MapPtr map)
    : openGLWidget(openGLWidget)
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
    stopwatch = std::make_shared<Stopwatch>();

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

void Simulator::onTimer()
{
    updateHumanVectors();

    openGLWidget.update();
}

void Simulator::updateHumanVectors()
{
    if (!map) return;

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

        for (size_t i = 0; i < humanList.size(); i++)
        {
            HumanPtr &human = humanList[i];
            if (!human) continue;
            HumanAdditionalData &humanAddData = human->getAdditionalData();

            for (size_t j = i + 1; j < humanList.size(); j++)
            {
                HumanPtr &other = humanList[j];
                if (!other) continue;
                HumanAdditionalData &otherAddData = human->getAdditionalData();

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

            // get movement vector
            const Vector &vec = human->getAdditionalData().intentionVector;
            const PositionF &pos = human->getPosition();

            human->setPosition(PositionF(vec.getX() + pos.x, vec.getY() + pos.y));
        }
    }
}


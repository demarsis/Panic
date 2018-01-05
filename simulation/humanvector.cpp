#include "humanvector.h"

Directions HumanVector::dirs = Directions(true);

Vector HumanVector::getIntentionVector(HumanPtr &human, FloorPtr &floor)
{
    if (!human) return Vector();
    if (!floor) return Vector();

    std::vector<CellPtr> humanCells = getHumanCells(human, floor);

    // get penalties for all directions
    std::vector<std::pair<Vector, Penalty>> possibleVectors;
    for (const Directions::DirVector &dirvect : dirs.getAllDirections())
    {
        Penalty pen = getCellsPenalty(floor, humanCells, dirvect.first);
        possibleVectors.push_back(std::make_pair(dirvect.second * HUMAN_INTENTION_SPEED_COEFF, pen));
    }
    if (possibleVectors.empty()) return Vector();

    // sort by min penalty
    std::sort(possibleVectors.begin(), possibleVectors.end(),
                [](const std::pair<Vector, Penalty> &left,
                   const std::pair<Vector, Penalty> &right) -> bool
                {
                    return left.second < right.second;
                }
    );

    return possibleVectors[0].first;
}

std::vector<CellPtr> HumanVector::getHumanCells(HumanPtr &human, FloorPtr &floor)
{
    std::vector<CellPtr> result;
    if (!human) return result;
    if (!floor) return result;

    Position center(human->getPosition().x, human->getPosition().y);
    int radius = human->getDiameter() / 2;

    Position lefttop(center.x - radius, center.y - radius);
    Position rightbottom(center.x + radius, center.y + radius);

    for (int x = lefttop.x; x <= rightbottom.x; x++)
    {
        for (int y = lefttop.y; y <= rightbottom.y; y++)
        {
            float currentRadius = (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y);
            if (currentRadius > radius * radius) continue;
            if (!floor->isValidPosition(Position(x, y))) continue;

            CellPtr cell = floor->getCell(x, y);
            if (cell)
            {
                result.push_back(cell);
            }
        }
    }

    return result;
}

Penalty HumanVector::getCellsPenalty(FloorPtr &floor, const std::vector<CellPtr> &cells, const Position &offset)
{
    if (!floor) return PENALTY_ZERO;

    Penalty result = 0;
    for (const CellPtr &cell : cells)
    {
        Position pos = cell->getPosition();
        pos.x += offset.x;
        pos.y += offset.y;

        if (!floor->isValidPosition(pos))
        {
            result += PENALTY_MAX;
            continue;
        }

        CellPtr &offsetedCell = floor->getCell(pos);
        if (!offsetedCell)
        {
            result += PENALTY_MAX;
            continue;
        }

        result += offsetedCell->getAdditionalData().wayPenalty;
    }

    return result;
}

bool HumanVector::isNewPositionIntersectedWithOther(const HumanPtr &human, const Vector &vec, const HumanPtr &other)
{
    // get new position
    PositionF pos = human->getPosition();
    pos.x += vec.getX();
    pos.y += vec.getY();

    // other's position
    const PositionF &othersPosition = other->getPosition();

    // check with others
    float squaredLength = (pos.x - othersPosition.x) * (pos.x - othersPosition.x) +
                          (pos.y - othersPosition.y) * (pos.y - othersPosition.y);

    float squaredDiameter = human->getDiameter() / 2 + other->getDiameter() / 2;
    squaredDiameter *= squaredDiameter;

    // check
    if (squaredLength < squaredDiameter) return true;
    return false;
}

Vector HumanVector::getPushesVector(const HumanPtr &human, const HumanPtr &other)
{
    const PositionF &humanPosition = human->getPosition();
    const PositionF &otherPosition = other->getPosition();

    float length = sqrt((humanPosition.x - otherPosition.x) * (humanPosition.x - otherPosition.x) +
                        (humanPosition.y - otherPosition.y) * (humanPosition.y - otherPosition.y));
    float radiuses = human->getDiameter() / 2 + other->getDiameter() / 2;

    float diff = radiuses - length;

    float k = diff / length;
    k /= 2;
    k *= HUMAN_PUSH_COEFF;

    float cx = (humanPosition.x - otherPosition.x) * k;
    float cy = (humanPosition.y - otherPosition.y) * k;

    return Vector(cx, cy);
}

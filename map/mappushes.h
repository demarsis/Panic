#ifndef MAPPUSHES_H
#define MAPPUSHES_H

#include <vector>
#include <math.h>
#include "simulation/vector.h"
#include "common/types.h"
#include <memory>

class MapPushes
{
    int width;
    int height;
    std::vector<std::vector<float>> pushes;

public:
    MapPushes(int width, int height);

    void addPush(const Position &pos, const Vector &vec);
    float getPush(const Position &pos) const;

    Size getSize() const;
    bool isValidPosition(const Position &pos) const;
};

typedef std::shared_ptr<MapPushes> MapPushesPtr;

#endif // MAPPUSHES_H

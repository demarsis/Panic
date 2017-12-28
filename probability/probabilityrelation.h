#ifndef PROBABILITYRELATION_H
#define PROBABILITYRELATION_H

#include <vector>
#include <utility>
#include "probability.h"

template <typename TYPE>
class ProbabilityRelation
{
    std::vector<std::pair<TYPE, int>> probs;
    int sum;

public:
    ProbabilityRelation() : sum(0) {}

    void addProbs(TYPE obj, int quantity)
    {
        if (quantity <= 0) return;
        probs.push_back(std::make_pair(obj, quantity));
        sum += quantity;
    }
    TYPE generate()
    {
        int rnd = Probability::instance().random(sum);

        int currentsum = 0;
        for (auto const p : probs)
        {
            currentsum += p.second;
            if (rnd < currentsum) return p.first;
        }

        return TYPE();
    }
};

#endif // PROBABILITYRELATION_H

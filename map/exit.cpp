#include "exit.h"

Exit::Exit(ExitType exitType)
    : exitType(exitType)
{

}

ExitType Exit::getExitType() const
{
    return exitType;
}

void Exit::setExitType(ExitType exitType)
{
    this->exitType = exitType;
}

bool Exit::isExit() const
{
    return getExitType() == ExitTypeExit;
}

Penalty Exit::getStartWayPenalty() const
{
    switch (exitType)
    {
    case ExitTypeNo:
        return PENALTY_MAX;
    case ExitTypeExit:
        return PENALTY_ZERO;
    }
    return PENALTY_MAX;
}


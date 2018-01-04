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


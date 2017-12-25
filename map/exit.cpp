#include "exit.h"

Exit::Exit(ExitType exitType)
    : exitType(exitType)
{

}

ExitType Exit::getExitType() const
{
    return exitType;
}

bool Exit::isExit() const
{
    return getExitType() == ExitTypeExit;
}


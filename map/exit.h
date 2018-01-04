#ifndef EXIT_H
#define EXIT_H

enum ExitType
{
    ExitTypeNo,
    ExitTypeExit
};

class Exit
{
    ExitType exitType;

public:
    Exit(ExitType exitType);

    ExitType getExitType() const;
    void setExitType(ExitType exitType);
    bool isExit() const;
};

#endif // EXIT_H

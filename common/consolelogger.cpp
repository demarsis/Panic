#include "consolelogger.h"

void ConsoleLogger::info(const QString &str)
{
    QTextStream cout(stdout);
    cout << str;
}

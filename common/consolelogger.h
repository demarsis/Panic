#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include <QString>
#include <QTextStream>

class ConsoleLogger
{
public:
    static void info(const QString &str);
};

#endif // CONSOLELOGGER_H

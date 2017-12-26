#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
#include <QString>
#include <QTime>
#include <memory>

class Stopwatch
{
    using clock_type = std::chrono::steady_clock;

    typedef std::chrono::time_point<clock_type> time_t;

    long all_time; // ms
    time_t start_time;
    bool started;

public:
    Stopwatch();

    void start();
    void pause();

    void reset();

    bool isStarted() const;
    bool isPaused() const;

    long getElapsedMs() const;
    QString toString() const;
};

typedef std::shared_ptr<Stopwatch> StopwatchPtr;

#endif // STOPWATCH_H

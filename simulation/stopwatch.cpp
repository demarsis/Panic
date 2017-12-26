#include "stopwatch.h"

Stopwatch::Stopwatch()
{
    reset();
}

void Stopwatch::start()
{
    started = true;
    start_time = clock_type::now();
}

void Stopwatch::pause()
{
    started = false;

    // count diff
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(clock_type::now() - start_time);
    all_time += diff.count();
}

void Stopwatch::reset()
{
    started = false;
    all_time = 0;
}

bool Stopwatch::isStarted() const
{
    return started;
}

bool Stopwatch::isPaused() const
{
    return !started;
}

long Stopwatch::getElapsedMs() const
{
    if (isStarted())
    {
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(clock_type::now() - start_time);
        return all_time + diff.count();
    }
    else
    {
        return all_time;
    }
}

QString Stopwatch::toString() const
{
    long ms = getElapsedMs();
    int sec = ms / 1000;
    ms = ms % 1000;
    int min = sec / 60;
    sec = sec % 60;

    QTime time(0, min, sec, ms);
    return time.toString("mm:ss:zzz");
}


#include "stopwatch.h"

Stopwatch::Stopwatch(int speedCoeff)
    : speedCoeff(speedCoeff)
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
    all_time += diff.count() * speedCoeff;
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
        return all_time + diff.count() * speedCoeff;
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
    ms = ms / 100;
    int min = sec / 60;
    sec = sec % 60;

    return
        QString("%1").arg(min, 2, 10, QChar('0')) + ":" +
        QString("%1").arg(sec, 2, 10, QChar('0')) + ":" +
            QString("%1").arg(ms , 1, 10, QChar('0'));
}

void Stopwatch::setSpeedCoeff(int speedCoeff)
{
    if (isStarted())
    {
        pause();
        this->speedCoeff = speedCoeff;
        start();
    }
    else
    {
        this->speedCoeff = speedCoeff;
    }
}


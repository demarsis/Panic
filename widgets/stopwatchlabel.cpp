#include "stopwatchlabel.h"

StopwatchLabel::StopwatchLabel(QWidget *parent) : QLabel(parent)
{
    QFont font("Courier New");
    font.setBold(true);
    font.setPixelSize(25);
    setFont(font);

    setAlignment(Qt::AlignCenter);

    stopwatch = std::make_shared<Stopwatch>();

    updateTime();

    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
    timer.start(100);
}

StopwatchPtr StopwatchLabel::getStopwatch()
{
    return stopwatch;
}

void StopwatchLabel::start()
{
    stopwatch->start();
}

void StopwatchLabel::pause()
{
    stopwatch->pause();
    updateTime();
}

void StopwatchLabel::reset()
{
    stopwatch->reset();
    updateTime();
}

void StopwatchLabel::updateTime()
{
    setText(stopwatch->toString());
}

void StopwatchLabel::on_timer()
{
    if (stopwatch->isStarted())
    {
        updateTime();
    }
}

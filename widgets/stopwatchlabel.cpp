#include "stopwatchlabel.h"

StopwatchLabel::StopwatchLabel(QWidget *parent) : QLabel(parent)
{
    QFont font("Lucida Console");
    font.setBold(true);
    font.setPixelSize(25);
    setFont(font);

    setAlignment(Qt::AlignCenter);

    updateTime();

    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
    timer.start(100);
}

StopwatchPtr StopwatchLabel::getStopwatch()
{
    return stopwatch;
}

void StopwatchLabel::setStopwatch(StopwatchPtr stopwatch)
{
    this->stopwatch = stopwatch;
    updateTime();
}

void StopwatchLabel::start()
{
    if (!stopwatch) return;
    stopwatch->start();
}

void StopwatchLabel::pause()
{
    if (!stopwatch) return;
    stopwatch->pause();
    updateTime();
}

void StopwatchLabel::reset()
{
    if (!stopwatch) return;
    stopwatch->reset();
    updateTime();
}

void StopwatchLabel::updateTime()
{
    if (!stopwatch)
    {
        setText("--:--:-");
        return;
    }
    setText(stopwatch->toString());
}

void StopwatchLabel::on_timer()
{
    if (!stopwatch) return;
    if (stopwatch->isStarted())
    {
        updateTime();
    }
}

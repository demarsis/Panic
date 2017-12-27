#ifndef STOPWATCHLABEL_H
#define STOPWATCHLABEL_H

#include <QLabel>
#include <QTimer>
#include <QObject>
#include "simulation/stopwatch.h"

class StopwatchLabel : public QLabel
{
    Q_OBJECT

    StopwatchPtr stopwatch;
    QTimer timer;

public:
    StopwatchLabel(QWidget *parent = 0);
    StopwatchPtr getStopwatch();
    void setStopwatch(StopwatchPtr stopwatch);

    void start();
    void pause();
    void reset();

private:
    void updateTime();

private slots:
    void on_timer();
};

#endif // STOPWATCHLABEL_H

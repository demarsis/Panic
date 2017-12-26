#ifndef BUTTONSTARTSTOP_H
#define BUTTONSTARTSTOP_H

#include "common/consolelogger.h"
#include <QWidget>
#include <QPushButton>

class ButtonStartStop : public QPushButton
{
    Q_OBJECT

public:
    explicit ButtonStartStop(QWidget *parent = 0);

    void start();
    void pause();

    bool isStarted();
    bool isPaused();

private:
    void updateIcon();

signals:
    void started();
    void paused();

public slots:

private slots:
    void toggled_(bool toggle_state);
};

#endif // BUTTONSTARTSTOP_H

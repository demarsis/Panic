#include "buttonstartstop.h"

ButtonStartStop::ButtonStartStop(QWidget *parent) : QPushButton(parent)
{
    setIconSize(QSize(40, 40));
    setCheckable(true);
    connect(this, SIGNAL(toggled(bool)), this, SLOT(toggled_(bool)));
    updateIcon();
}

void ButtonStartStop::start()
{
    setChecked(true);
}

void ButtonStartStop::pause()
{
    setChecked(false);
}

bool ButtonStartStop::isStarted()
{
    return isChecked();
}

bool ButtonStartStop::isPaused()
{
    return !isChecked();
}

void ButtonStartStop::resetToUnpausedState()
{
    blockSignals(true);
    setChecked(false);
    updateIcon();
    blockSignals(false);
}

void ButtonStartStop::updateIcon()
{
    if (isChecked())
    {
        setIcon(QIcon(":/icons/pause.png"));
    }
    else
    {
        setIcon(QIcon(":/icons/play.png"));
    }

}

void ButtonStartStop::toggled_(bool toggle_state)
{
    updateIcon();
    if (toggle_state) emit started();
    else emit paused();
}


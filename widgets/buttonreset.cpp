#include "buttonreset.h"

ButtonReset::ButtonReset(QWidget *parent) : QPushButton(parent)
{
    setIconSize(QSize(35, 35));
    setIcon(QIcon(":/icons/reset.png"));
}


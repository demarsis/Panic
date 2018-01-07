#include "combosimulationspeed.h"

ComboSimulationSpeed::ComboSimulationSpeed(QWidget *parent)
    : QComboBox(parent)
{
    addItem("1x", (int)1);
    addItem("2x", (int)2);
    addItem("5x", (int)5);
    addItem("10x", (int)10);
}

int ComboSimulationSpeed::getSpeed() const
{
    QVariant data = currentData();
    return data.toInt();
}


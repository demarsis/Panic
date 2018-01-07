#ifndef COMBOSIMULATIONSPEED_H
#define COMBOSIMULATIONSPEED_H

#include <QWidget>
#include <QComboBox>

class ComboSimulationSpeed : public QComboBox
{
    Q_OBJECT

public:
    ComboSimulationSpeed(QWidget *parent = 0);

    int getSpeed() const;
};

#endif // COMBOSIMULATIONSPEED_H

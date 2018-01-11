#ifndef COMBOPANIC_H
#define COMBOPANIC_H

#include <QWidget>
#include <QComboBox>
#include "human/panic.h"
#include "probability/probabilityrelation.h"

class ComboPanic : public QComboBox
{
    Q_OBJECT

public:
    ComboPanic(QWidget *parent = 0);

    ProbabilityRelation<PanicType> getPanicProbability() const;
};

#endif // COMBOPANIC_H

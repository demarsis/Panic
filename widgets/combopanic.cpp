#include "combopanic.h"

ComboPanic::ComboPanic(QWidget *parent)
    : QComboBox(parent)
{
    addItem("Отсутствие паники");
    addItem("Низкий уровень");
    addItem("Средний уровень");
    addItem("Высокий уровень");
}

ProbabilityRelation<PanicType> ComboPanic::getPanicProbability() const
{
    ProbabilityRelation<PanicType> result;
    switch (currentIndex())
    {
    case 0:
        result.addProbs(PanicTypeNo, 100);
        break;
    case 1:
        result.addProbs(PanicTypeNo,    60);
        result.addProbs(PanicTypeMinor, 40);
        break;
    case 2:
        result.addProbs(PanicTypeNo,    20);
        result.addProbs(PanicTypeMinor, 40);
        result.addProbs(PanicTypeMajor, 40);
        break;
    case 3:
        result.addProbs(PanicTypeMinor, 20);
        result.addProbs(PanicTypeMajor, 80);
        break;
    }

    return result;
}


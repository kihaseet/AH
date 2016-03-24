#ifndef ABSTRACTCONDITION_H
#define ABSTRACTCONDITION_H
#include "data.h"

enum CONDITION_TYPE{      //типы триггеров, задающие условия срабатывания; объект - зона или игрок
    TR_ZONE_EQUAL,      //объект находится в зоне
    TR_CONTAIN_CARD,    //объект содержит карту(ы)
    TR_CONTAIN_TOKEN,   //объект содержит жетон(ы)
    TR_MAKING_CHECK,    //объект проходит проверку
    TR_CURRENT_PHASE,    //текущая фаза равна
    TR_PARAM_EQUAL      //сравнение параметра объекта с другим
};

class AbstractCondition
{
protected:
    int cParam;
public:
    AbstractCondition(int cParam);
    virtual bool isCheck() = 0;

    //friend bool operator==(const IObject &left, const IObject &right);
};

class ConditionsCountMonsterOver:public AbstractCondition
{
public:
    ConditionsCountMonsterOver(int cParam):AbstractCondition(cParam) {}
    bool isCheck();
};

#endif // ABSTRACTCONDITION_H

#include "abstractcondition.h"


AbstractCondition::AbstractCondition(int cParam)
{
    this->cParam = cParam;
}


bool ConditionsCountMonsterOver::isCheck()
{
    //int i = Data::getData()->countMonster;
    return ((Data::getData()->countMonster) >= cParam);
}

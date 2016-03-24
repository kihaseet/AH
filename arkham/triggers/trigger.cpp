#include "trigger.h"


bool Trigger::checkTriggerConditions()
{
    //при совпадении типов события и триггера
    foreach (AbstractCondition* condition, conditionList) {
        if(!condition) continue;
        if(!condition->isCheck()) return false;
    }
    return true;
}

bool Trigger::applyTrigger(EventObject *event)
{
    this->object = event->who;
    this->target = event->target;
    this->applyTrigger();
    return this->interrupt;
}


Trigger *Trigger::createTrigger(EVENT_TYPE triggerID, IObject* who, IObject* target, OBJECT_TYPE param)
{
    RegistryTrigger& r = getRegistryTrigger();
    if(r.find(triggerID) != r.end()){
        Trigger* t = r[triggerID]->clone();
        t->object = who;
        t->target = target;
        t->triggerID = triggerID;
        t->condition = TT_NULL;
        t->paramType = param;
        t->interrupt = false;
        return t;
    }
    return 0;
}

Trigger *Trigger::createConditionTrigger(EVENT_TYPE triggerID, EVENT_TYPE triggerCondition, bool interrupt, QList<AbstractCondition *> conditionList)
{
    Trigger* t = Trigger::createTrigger(triggerID,0,0);
    if(t!=0){
        t->condition = triggerCondition;
        t->interrupt = interrupt;
        t->conditionList.append(conditionList);
    }
    return t;
}

Trigger *Trigger::createConditionTrigger(EVENT_TYPE triggerID, EVENT_TYPE triggerCondition, bool interrupt, AbstractCondition* condition)
{
    Trigger* t = Trigger::createTrigger(triggerID,0,0);
    if(t!=0){
        t->condition = triggerCondition;
        t->interrupt = interrupt;
        t->conditionList.append(condition);
    }
    return t;
}


void Trigger::addPrototypeTrigger(EVENT_TYPE triggerID, Trigger *prototype)
{
    RegistryTrigger& r = getRegistryTrigger();
    r[triggerID] = prototype;
}

void Trigger::removePrototypeTrigger(EVENT_TYPE triggerID)
{
    RegistryTrigger& r = getRegistryTrigger();
    r.erase(r.find(triggerID));
}

RegistryTrigger &getRegistryTrigger()
{
    static RegistryTrigger _instance;
    return _instance;
}

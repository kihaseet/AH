#ifndef TRIGGER_H
#define TRIGGER_H
#include <QList>
#include <QDebug>
#include "types.h"
#include "triggers/abstractcondition.h"

//class Dummy {};
class Trigger;
class AbstractCondition;
class EventObject;

static int triggerCount = 0;
typedef QMap<EVENT_TYPE, Trigger*> RegistryTrigger;
RegistryTrigger& getRegistryTrigger();


class Trigger
{
private:
    QString text;
public:
    EVENT_TYPE condition;                       //условие срабатывания триггера
    EVENT_TYPE triggerID;
    bool interrupt;                             //прерывает ли триггер текущее событие
    QList<AbstractCondition*> conditionList;
    virtual Trigger* clone() const = 0;
    IObject* object;
    IObject* target;
    OBJECT_TYPE paramType;
    bool checkTriggerConditions();
    virtual void applyTrigger() = 0;
    bool applyTrigger(EventObject* event);      //для триггеров пула - инициализация и возвращение прерывания

    friend bool operator ==(const Trigger& left, const Trigger& right)
    {
        return left.triggerID == right.triggerID;
    }
    static Trigger *createTrigger(EVENT_TYPE triggerID, IObject *who = 0, IObject *target = 0, OBJECT_TYPE param = OBJECT_UNKNOWN);
    static Trigger *createConditionTrigger(EVENT_TYPE triggerID,                //создать условный триггер (для пула), что делает
                                           EVENT_TYPE triggerCondition,         //при каком событии
                                           bool interrupt,                      //прерывает ли основное событие
                                           QList<AbstractCondition*> conditionList = QList<AbstractCondition*>());  //список условий
    static Trigger *createConditionTrigger(EVENT_TYPE triggerID, EVENT_TYPE triggerCondition, bool interrupt, AbstractCondition* condition);
protected:

    void addPrototypeTrigger(EVENT_TYPE triggerID, Trigger *prototype);
    void removePrototypeTrigger(EVENT_TYPE triggerID);
};

#endif // TRIGGER_H

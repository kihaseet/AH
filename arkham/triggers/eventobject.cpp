#include "eventobject.h"

void EventObject::runEvent()
{
    iniEventTrigger();
    bool interrupt = false;     //прерывание после выполнения пула триггеров
    foreach (Trigger *trigger, Data::getData()->triggerPool) {       //проверка пула триггеров для выполнения подходящих тригеров ДО события
        // if((trigger->object == 0) || trigger->object->getObjectType() == who->getObjectType()){
        if((this->what == trigger->condition) && trigger->checkTriggerConditions()){
            interrupt |= trigger->applyTrigger(this);
        }
    }
    if(!interrupt)              //если прерывания не было, применить действия
        foreach (Trigger *trigger, triggerList) {                        //выполнение триггеров события
            if(trigger->checkTriggerConditions())
                trigger->applyTrigger();
        }
    //TODO обеспечить удаление события после запуска

}

EventObject *EventObject::createEvent(EVENT_TYPE eventID, IObject* who, IObject* target)
{
    RegistryEvent& r = getRegistryEvent();
    if(r.find(eventID) != r.end()){
        EventObject *t = r[eventID]->clone();
        t->who = who;
        t->target = target;
        t->commWho = OBJECT_UNKNOWN;
        t->commTarget = OBJECT_UNKNOWN;
        t->what = eventID;
        //t->iniEventTrigger();
        return t;
    }

    return 0;
}

EventObject *EventObject::createEvent(EVENT_TYPE eventID, IObject *who, OBJECT_TYPE target)
{
    RegistryEvent& r = getRegistryEvent();
    if(r.find(eventID) != r.end()){
        EventObject *t = r[eventID]->clone();
        t->who = who;
        t->target = 0;
        t->commWho = OBJECT_UNKNOWN;
        t->commTarget = target;
        t->what = eventID;
       // t->iniEventTrigger();
        return t;
    }
    return 0;
}

EventObject *EventObject::createEvent(EVENT_TYPE eventID, OBJECT_TYPE who, OBJECT_TYPE target)
{
    RegistryEvent& r = getRegistryEvent();
    if(r.find(eventID) != r.end()){
        EventObject *t = r[eventID]->clone();
        t->commWho = who;
        t->commTarget = target;
        t->what = eventID;
       // t->iniEventTrigger();
        return t;
    }

    return 0;
}

void EventObject::appendTrigger(Trigger *trigger)
{
    triggerList.append(trigger);
}

void EventObject::removeTrigger(EVENT_TYPE eventID, Trigger *trigger)
{
    RegistryEvent& r = getRegistryEvent();
    r[eventID]->triggerList.removeAll(trigger);
}

void EventObject::addPrototypeEvent(EVENT_TYPE eventID, EventObject *prototype)
{
    RegistryEvent& r = getRegistryEvent();
    r[eventID] = prototype;
}

void EventObject::removePrototypeEvent(EVENT_TYPE eventID)
{
    RegistryEvent& r = getRegistryEvent();
    r.erase(r.find(eventID));
}

RegistryEvent& getRegistryEvent()
{
    static RegistryEvent _instance;
    return _instance;
}

#ifndef EVENTOBJECT_H
#define EVENTOBJECT_H
#include <QList>
#include <QMap>
#include "types.h"
#include "tokens/iobject.h"
#include "triggers/trigger.h"

class EventObject;
class Trigger;

typedef QMap<EVENT_TYPE,EventObject*> RegistryEvent;
RegistryEvent& getRegistryEvent();


class EventObject
{
public:
    EVENT_TYPE what;
    IObject*  who;
    IObject*  target;
    OBJECT_TYPE commWho;        //для указания общего типа
    OBJECT_TYPE commTarget;     //объектов или цели
    void runEvent();
    virtual EventObject* clone() const = 0;
    virtual void iniEventTrigger() = 0;
    virtual ~EventObject(){}
    static EventObject *createEvent(EVENT_TYPE eventID, IObject *who, IObject *target);
    static EventObject *createEvent(EVENT_TYPE eventID, IObject *who, OBJECT_TYPE target);
    static EventObject *createEvent(EVENT_TYPE eventID, OBJECT_TYPE who, OBJECT_TYPE target);
    void appendTrigger(Trigger* trigger);
    static void removeTrigger(EVENT_TYPE eventID, Trigger* trigger);
protected:
    static void addPrototypeEvent(EVENT_TYPE eventID, EventObject* prototype);
    static void removePrototypeEvent(EVENT_TYPE eventID);
    QList<Trigger*> triggerList;

};



#endif // EVENTOBJECT_H

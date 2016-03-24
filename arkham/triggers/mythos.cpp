#include "mythos.h"

Mythos::Mythos(QString name):IObject(name, CARD_MYTHOS)
{

}


void Mythos::appendEventToResolveList(EventObject *event)
{
    eventResolveList.append(event);
}

void Mythos::ResolveEvents()
{
    foreach (EventObject* event, eventResolveList) {
        event->runEvent();
    }
}


#ifndef MYTHOS_H
#define MYTHOS_H
#include <QList>
#include "triggers/eventobject.h"

class EventObject;

class Mythos: public IObject
{
    QList<EventObject*> eventResolveList;               //список разыгрываемых во время мифа событий
public:
    Mythos(QString name);
    void appendEventToResolveList(EventObject* event);  //добавить событие в конец резолв-списка
    void ResolveEvents();                               //разыгрывание событий Мифа
};

#endif // MYTHOS_H

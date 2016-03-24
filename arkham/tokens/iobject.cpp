#include "iobject.h"

OBJECT_TYPE IObject::getObjectType() const
{
    return objectType;
}

void IObject::setObjectType(const OBJECT_TYPE &value)
{
    objectType = value;
}

int IObject::getIObjectID()
{
    return ID;
}

void IObject::appendToPlace(IObject *object)
{
    Q_ASSERT(object != 0);
    place = object;
    place->tokenPool.append(object);
}

void IObject::removeFromPlace()
{
    Q_ASSERT(place != 0);
    place->tokenPool.removeAll(this);
    place = 0;
}

IObject::IObject(QString name, OBJECT_TYPE type)
{
    place = 0;
    objectType = type;
    this->name = name;
    ID = ObjectCount++;
}


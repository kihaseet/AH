#ifndef IOBJECT_H
#define IOBJECT_H
#include <QString>
#include <QList>
#include "types.h"
static int ObjectCount = 0;

class IObject
{
protected:
    OBJECT_TYPE objectType;
    int ID;
public:
    QList<IObject*> tokenPool;            //список объектов "сверху" на объекте
    IObject* place;    //местонахождение объекта        (локация или сыщик или другой объект)
    QString name;
    IObject(QString name, OBJECT_TYPE type);
    OBJECT_TYPE getObjectType() const;
    void setObjectType(const OBJECT_TYPE &value);
    int getIObjectID();
    void appendToPlace(IObject* object);
    void removeFromPlace();
};

//чтобы можно было указывать его в качестве цели


#endif // IOBJECT_H

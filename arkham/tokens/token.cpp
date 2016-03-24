#include "token.h"
#include "data.h"

Token::Token(QString name, OBJECT_TYPE type):IObject(name, type)
{
    place = 0;
}

void Token::moveToken(IObject* to)  //перевесть to к типу location
{
    //TODO не забыть подправить, когда объект можно будет помещать и на карты
    Q_ASSERT(to->getObjectType()==MAP_LOCATION ||
             to->getObjectType()==MAP_OUTSKIRTS ||
             to->getObjectType()==MAP_SKY);
    removeToken();
    placeToken(to);
}

void Token::placeToken(IObject* to)
{
    Q_ASSERT(to->getObjectType()==MAP_LOCATION ||
             to->getObjectType()==MAP_OUTSKIRTS ||
             to->getObjectType()==MAP_SKY);
    if(to->getObjectType()==MAP_OUTSKIRTS){
        Data::getData()->outskirts->tokenPool.append(this);
    }
    else if(to->getObjectType()==MAP_SKY){
        Data::getData()->sky->tokenPool.append(this);
    }
    else if(to->getObjectType()==MAP_LOCATION){
        static_cast<location*>(to)->tokenPool.append(this);
    }
    place = to;

}

void Token::removeToken()
{
    if(place != 0)
        static_cast<location*>(place)->tokenPool.removeAll(this);
}


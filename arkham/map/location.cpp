#include "location.h"

bool location::getIsStreet() const
{
    return isStreet;
}

void location::setIsStreet(bool value)
{
    isStreet = value;
}

location::location(QString name, int idDistrict, bool isStable, bool isStreet): IObject(name,MAP_LOCATION)
{
    this->idDistrict = idDistrict;
    this->isStable = isStable;
    this->isStreet = isStreet;
}

QList<Monster *> location::getMonsters()
{
    QList<Monster*> lst;
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType()==TOKEN_MONSTER){
            lst.append(static_cast<Monster*>(token));
        }
    }
    return lst;
}

Gate *location::getGate()
{
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType()==TOKEN_GATE){
            return static_cast<Gate*>(token);
        }
    }
    return 0;
}

bool location::containPlayer()
{
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType() == MARKER_INVESTIGATOR)
            return true;
    }
    return false;
}

bool location::containAquatic()
{
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType() == MARKER_AQUATIC)
            return true;
    }
    return false;
}

Token* location::getSeal()    //содержит ли локация печать, если да - возвращает указатель на жетон печати, если нет - возвращает 0
{
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType()==TOKEN_ELDER_SIGN)
            return static_cast<Token*>(token);
    }
    return 0;
}

QList<investigator *> location::getPlayersOnLocation()
{
    QList<investigator *> lst;
    foreach (IObject* token, tokenPool) {
        if(token->getObjectType() == MARKER_INVESTIGATOR)
           lst.append(static_cast<investigator*>(token));
    }
    return lst;
}


#ifndef CARD_H
#define CARD_H
#include <QDebug>
#include <QList>
#include "tokens/iobject.h"

class Card:public IObject
{
protected:
    bool isExhausted;
    short useHand;
    short primeParam;   //первый параметр на карте; +X к проверкам, и т.д.
    CARD cardType;
    ITEM_TYPE itemType;
    QList <ITEM_SETTING> itemSettings;
public:
    Card(QString name, CARD card_type, OBJECT_TYPE type);
    virtual void appendToPlayer(IObject* player)
    {
        appendToPlace(player);
        qDebug()<<"append to player Card";
    }          //пассивные свойства - триггеры
    virtual void removeFromPlayer()        //удаление пассивных свойств
    {
        stopUseCardAction();
        removeFromPlace();
    }
    virtual void useCardAction(){}           //задействование карты
    virtual void stopUseCardAction(){}
    short getUseHand() const;
    CARD getCardType() const;
};

class CardCommonItem:public Card
{
protected:
    short price;
public:
    CardCommonItem(QString name);   /* передавать структуру, описывающую предмет
                                     *
                                     * для этого составить списки всех воздействий предметов,
                                     * чтобы можно было в конструкторе определять, как его собирать
                                     * для этого составить классы для каждого действия -_-
                                     */

};

#endif // CARD_H

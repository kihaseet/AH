#include "card.h"

short Card::getUseHand() const
{
    return useHand;
}

CARD Card::getCardType() const
{
    return cardType;
}

Card::Card(QString name, CARD card_type, OBJECT_TYPE type):IObject(name,type)
{
    cardType = card_type;
    isExhausted = false;
}


CardCommonItem::CardCommonItem(QString name):Card(name,CT_COMMON,CARD_ITEM)
{
}

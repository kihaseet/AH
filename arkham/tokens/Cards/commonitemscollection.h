#ifndef COMMONITEMSCOLLECTION_H
#define COMMONITEMSCOLLECTION_H
#include "card.h"


class Common18Derringer:public CardCommonItem
{
public:
    Common18Derringer(): CardCommonItem(".18 Derringer")
    {
        itemType = PHYSICAL_WEAPON;
        primeParam = 2;
        itemSettings.append(ITEM_ONE_HAND);
        itemSettings.append(ITEM_CANNOT_BE_LOST);
        price = 3;
        useHand = 1;
    }
    void useCardAction();
    void stopUseCardAction();

    // Card interface
public:
   // void appendToPlayer(IObject *player)
  //  {
  //      qDebug()<<"append to player Derringer";
  //      Card::appendToPlayer(player);
  //  }
};




#endif // COMMONITEMSCOLLECTION_H

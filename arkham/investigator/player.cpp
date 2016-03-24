#include "player.h"

short investigator::getSneak() const
{
    return currSneak + status.value(ET_SNEAK,0);
}

void investigator::setSneak(short value)
{
    currSneak = value;
}

investigator::investigator(QString playername):Token(playername, MARKER_INVESTIGATOR)
{   
    posLoreLuck = 0;
    posFightWill = 0;
    posSneakSpeed = 0;
    modifyCombat = 0;
    modifyEvade = 0;
    modifyHorror = 0;
    modifySpell = 0;
    freeHands = 2;
    currHands = 0;
}

/*
 * Бросок кубов,    count  - количество бросаемых кубов, возвращает количество успехов
 *                  pen - бонус к значению
 */
int investigator::RollDice(int count, int pen=0)
{

    int success = 0;
    while(count > 0) {
        if(OneRollDie(pen) >= 5)
            success++;
        count--;
    }
    return success;
}

/*
 * Сделать бросок кубика, вернуть значение
 *      N - изменение значения на выпавшей грани
 */
int investigator::OneRollDie(int N=0)
{
    QTime time(0,0,0);
    qsrand(time.secsTo(QTime::currentTime()));
    return (qrand() % 6) + N;
}

/*
 * Проверка одного из навыков сыщика, возвращает количество успехов
 * check - проверяемый навык
 * pen - штраф или бонус к проверке
 * limit - требуемое количество успехов, если не достигнут, вернет 0
 */
int investigator::CheckAbility(ABILITY check, int pen = 0, int limit = 1)
{
    int success = 0;
    int N = 0;      //бонус к значению
    int M = pen;      //бонус к проверке
   // if(status.contains(check))
    //    M = status.value(check);
   // if(status.contains(check+1))
  //      N = status.value(check+1);
  //  if(status.contains(ET_BLESS)) N++;
  //  if(status.contains(ET_CURSE)) N--;
    switch (check) {
    case ABT_FIGHT:
        success = RollDice(currFight+M,N);
        break;
    case ABT_WILL:
        success = RollDice(currWill+M,N);
        break;
    case ABT_SPEED:
        success = RollDice(currSpeed+M,N);
        break;
    case ABT_SNEAK:
        success = RollDice(currSneak+M,N);
        break;
    case ABT_LORE:
        success = RollDice(currLore+M,N);
        break;
    case ABT_LUCK:
        success = RollDice(currLuck+M,N);
        break;
    default:
        break;
    }
    if(success < limit)
        return 0;
    else
        return success;
}


short investigator::getModifyCombat() const
{
    return modifyCombat;
}

void investigator::setModifyCombat(short value)
{
    modifyCombat = value;
}

short investigator::getModifyHorror() const
{
    return modifyHorror;
}

void investigator::setModifyHorror(short value)
{
    modifyHorror = value;
}

short investigator::getModifySpell() const
{
    return modifySpell;
}

void investigator::setModifySpell(short value)
{
    modifySpell = value;
}

short investigator::getModifyEvade() const
{
    return modifyEvade;
}

void investigator::setModifyEvade(short value)
{
    modifyEvade = value;
}

short investigator::getCurrHands() const
{
    return currHands;
}

void investigator::setCurrHands(short value)
{
    currHands = value;
}

short investigator::getFreeHands() const
{
    return freeHands;
}

void investigator::setFreeHands(short value)
{
    freeHands = value;
}

void investigator::appendCardInHands(Card* weapon)
{
    if((freeHands - currHands) >= weapon->getUseHand()){
        cardInHands.append(weapon);
        currHands += weapon->getUseHand();
    }
}

void investigator::removeCardFromHands(Card *weapon)
{
    if(cardInHands.contains(weapon)){
        cardInHands.removeAll(weapon);
        currHands -= weapon->getUseHand();
    }
}

void investigator::appendObjectToInventory(IObject *object)
{
    Q_ASSERT(object != 0);
    if(object->place != 0)                              //если объект где-то находится
        object->place->tokenPool.removeAll(object);     //убираем его из списка объектов в этом "где-то"
    if(object->getObjectType() == TOKEN_CLUE) {
        personalClueCup.append(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_POWER) {
        personalPowerCup.append(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_MONSTER) {
        personalMonsterTrophy.append(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_GATE) {
        personalGateTrophy.append(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == CARD_ITEM) {
        inventoryCard.append(static_cast<Card*>(object));
        static_cast<Card*>(object)->appendToPlayer(this);
    }
}

void investigator::removeObjectFromInventory(IObject *object)
{
    Q_ASSERT(object != 0);
    if(object->getObjectType() == TOKEN_CLUE) {
        personalClueCup.removeAll(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_POWER) {
        personalPowerCup.removeAll(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_MONSTER) {
        personalMonsterTrophy.removeAll(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == TOKEN_GATE) {
        personalGateTrophy.removeAll(static_cast<Token*>(object));
    }
    else if(object->getObjectType() == CARD_ITEM) {
        inventoryCard.removeAll(static_cast<Card*>(object));
        static_cast<Card*>(object)->removeFromPlayer();
    }
}


void investigator::increaseSneak()
{
    if(posSneakSpeed < 3){
        posSneakSpeed--;
        currSneak = SneakTrack[posSneakSpeed];
        currSpeed = SpeedTrack[posSneakSpeed];
    }
}

void investigator::increaseSpeed()
{
    if(posSneakSpeed > 0){
        posSneakSpeed++;
        currSneak = SneakTrack[posSneakSpeed];
        currSpeed = SpeedTrack[posSneakSpeed];
    }
}

void investigator::increaseWill()
{
    if(posFightWill < 3){
        posFightWill--;
        currFight = SneakTrack[posFightWill];
        currWill = SpeedTrack[posFightWill];
    }
}

void investigator::increaseFight()
{
    if(posFightWill > 0){
        posFightWill++;
        currFight = FightTrack[posFightWill];
        currWill = WillTrack[posFightWill];
    }

}

void investigator::increaseLore()
{
    if(posLoreLuck < 3){
        posLoreLuck++;
        currLore = LoreTrack[posLoreLuck];
        currLuck = LuckTrack[posLoreLuck];
    }
}

void investigator::increaseLuck()
{
    if(posLoreLuck > 0){
        posLoreLuck--;
        currLore = LoreTrack[posLoreLuck];
        currLuck = LuckTrack[posLoreLuck];
    }
}

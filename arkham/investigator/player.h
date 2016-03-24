#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QTime>
#include <QMap>
#include <QVector>
#include "types.h"
#include "tokens/token.h"
#include "tokens/Cards/card.h"

class investigator:public Token
{
protected:

    int id;
    QMap<EFFECT, int> status;   //эффект - значение
    short currStamina;
    short StaminaMaximum;
    short currSanity;
    short SanityMaximum;
    short Focus;
    short currFocus;
    short freeHands;
    short currHands;
    short money;

    QVector<short>SneakTrack;
    QVector<short>SpeedTrack;
    QVector<short>FightTrack;
    QVector<short>WillTrack;
    QVector<short>LoreTrack;
    QVector<short>LuckTrack;

    short posSneakSpeed;        //позиция ползунка на первой полоске    0-3
    short posFightWill;         //позиция ползунка на второй полоске    0-3
    short posLoreLuck;          //позиция ползунка на третьей полоске   0-3

    short currSpeed;
    short currSneak;
    short currFight;
    short currWill;
    short currLore;
    short currLuck;

    short modifyCombat;
    short modifyHorror;
    short modifySpell;
    short modifyEvade;

    QList <Card*>   inventoryCard;
    QList <Card*>   cardInHands;        //для оружия в бою
    QList <Token*>  personalClueCup;
    QList <Token*>  personalPowerCup;
    QList <Token*>  personalMonsterTrophy;
    QList <Token*>  personalGateTrophy;

public:
    virtual void increaseSneak();
    virtual void increaseSpeed();
    virtual void increaseWill();
    virtual void increaseFight();
    virtual void increaseLore();
    virtual void increaseLuck();

    investigator(QString playername);
    int RollDice(int count, int pen);
    int OneRollDie(int N);
    int CheckAbility(ABILITY check, int pen, int limit);

    short getSneak() const;
    void setSneak(short value);

    short getModifyCombat() const;
    void setModifyCombat(short value);
    short getModifyHorror() const;
    void setModifyHorror(short value);
    short getModifySpell() const;
    void setModifySpell(short value);
    short getModifyEvade() const;
    void setModifyEvade(short value);
    short getCurrHands() const;
    void setCurrHands(short value);
    short getFreeHands() const;
    void setFreeHands(short value);
    void appendCardInHands(Card* weapon);
    void removeCardFromHands(Card* weapon);
    void appendObjectToInventory(IObject* object);
    void removeObjectFromInventory(IObject* object);
};



#endif // PLAYER_H

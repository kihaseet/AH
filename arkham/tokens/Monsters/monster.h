#ifndef MONSTER_H
#define MONSTER_H
#include <QList>
#include "tokens/token.h"
#include "map/location.h"


class Monster:public Token
{
protected:

    MONSTER monsterType;
    OBJECT_TYPE monsterSymbol;
    int Nightmarish;
    int Overwhelming;
    QList<MONSTER_SPECIAL> monsterSpecials;
    int Horror;         //штраф проверки воли
    int loseSanity;     //урон рассудку
    int Combat;         //штраф проверки боя
    int loseStamina;    //урон здоровью
    int Awareness;      //штраф скрытности (бдительность)
    int Toughness;      //стойкость

public:
    virtual void MonsterMove(OBJECT_TYPE way) = 0;

    Monster(QString name, OBJECT_TYPE symbol);
    MONSTER getMonsterType() const;
    void setMonsterType(const MONSTER &value);
    QList<MONSTER_SPECIAL> getMonsterSpecials() const;
    void appendMonsterSpecials(MONSTER_SPECIAL ms);
    void deleteMonsterSpecials(MONSTER_SPECIAL ms);
    int getOverwhelming() const;
    void setOverwhelming(int value);
    int getNightmarish() const;
    void setNightmarish(int value);
    int getHorror() const;
    void setHorror(int value);
    int getLoseSanity() const;
    void setLoseSanity(int value);
    int getCombat() const;
    void setCombat(int value);
    int getLoseStamina() const;
    void setLoseStamina(int value);
    int getAwareness() const;
    void setAwareness(int value);
    int getToughness() const;
    void setToughness(int value);
    OBJECT_TYPE getMonsterSymbol() const;
};


class MonsterBlack: public Monster
{
public:
    MonsterBlack(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};

class MonsterRed: public Monster
{
public:
    MonsterRed(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};

class MonsterBlue: public Monster
{
public:
    MonsterBlue(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};

class MonsterYellow: public Monster
{
public:
    MonsterYellow(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};

class MonsterPurple: public Monster
{
public:
    MonsterPurple(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};

class MonsterGreen: public Monster
{
protected:
    void SpecialMoveChthonian();
    void SpecialMoveColourOutOfSpace();
    void SpecialMoveDarkDruid();
    void SpecialMoveHoundOfTindalos();
    void SpecialMoveHuntingHorror();
    void SpecialMoveLloigor();
    void SpecialMoveShadowyFigure();
    void SpecialMoveTheDunwichHorror();
    void SpecialMoveWereeolf();
public:
    MonsterGreen(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
    virtual void useSpecialMove() = 0;


};

class MonsterOrange: public Monster
{
public:
    MonsterOrange(QString name, OBJECT_TYPE symbol);
    void MonsterMove(OBJECT_TYPE way);
};


#endif // MONSTER_H

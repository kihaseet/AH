#ifndef TRIGGERCOLLECTIONS_H
#define TRIGGERCOLLECTIONS_H
#include "triggers/trigger.h"

class TriggerGateOpen:public Trigger
{
public:
    Trigger *clone() const
    {
        return new TriggerGateOpen(*this);
    }
    void applyTrigger();
private:
    TriggerGateOpen(Dummy)
    {
        Trigger::addPrototypeTrigger(TT_GATE_OPEN,this);
    }
    TriggerGateOpen()
    {
    }
    static TriggerGateOpen prototype;
};

class TriggerMonsterAppend:public Trigger
{
public:
    Trigger *clone() const{return new TriggerMonsterAppend(*this);}
    void applyTrigger();
private:
    TriggerMonsterAppend(Dummy){Trigger::addPrototypeTrigger(TT_MONSTER_APPEND,this);}
    TriggerMonsterAppend(){}
    static TriggerMonsterAppend prototype;
};

class TriggerObjectAppend:public Trigger
{
public:
    Trigger *clone() const{return new TriggerObjectAppend(*this);}
    void applyTrigger();
private:
    TriggerObjectAppend(Dummy){Trigger::addPrototypeTrigger(TT_OBJECT_APPEND,this);}
    TriggerObjectAppend(){}
    static TriggerObjectAppend prototype;
};

class TriggerMonsterMove:public Trigger
{
public:
    Trigger *clone() const{return new TriggerMonsterMove(*this);}
    void applyTrigger();
private:
    TriggerMonsterMove(Dummy){Trigger::addPrototypeTrigger(TT_MONSTER_MOVE,this);}
    TriggerMonsterMove(){}
    static TriggerMonsterMove prototype;
};

class TriggerObjectMove:public Trigger
{
public:
    Trigger *clone() const{return new TriggerObjectMove(*this);}
    void applyTrigger();
private:
    TriggerObjectMove(Dummy){Trigger::addPrototypeTrigger(TT_OBJECT_MOVE,this);}
    TriggerObjectMove(){}
    static TriggerObjectMove prototype;
};

class TriggerSymbolMove:public Trigger
{
public:
    Trigger *clone() const{return new TriggerSymbolMove(*this);}
    void applyTrigger();
private:
    TriggerSymbolMove(Dummy){Trigger::addPrototypeTrigger(TT_SYMBOL_MOVE,this);}
    TriggerSymbolMove(){}
    static TriggerSymbolMove prototype;
};

class TriggerMonsterMoveToOutskirts:public Trigger
{
public:
    Trigger *clone() const{return new TriggerMonsterMoveToOutskirts(*this);}
    void applyTrigger();
private:
    TriggerMonsterMoveToOutskirts(Dummy){Trigger::addPrototypeTrigger(TT_MONSTER_OUTSKIRTS,this);}
    TriggerMonsterMoveToOutskirts(){}
    static TriggerMonsterMoveToOutskirts prototype;
};

class TriggerResolveCard:public Trigger
{
public:
    Trigger *clone() const{return new TriggerResolveCard(*this);}
    void applyTrigger();
private:
    TriggerResolveCard(Dummy){Trigger::addPrototypeTrigger(TT_RESOLVE_CARD,this);}
    TriggerResolveCard(){}
    static TriggerResolveCard prototype;
};

class TriggerIncreaseDoom:public Trigger
{
public:
    Trigger *clone() const{return new TriggerIncreaseDoom(*this);}
    void applyTrigger();
private:
    TriggerIncreaseDoom(Dummy){Trigger::addPrototypeTrigger(TT_INCREASE_DOOM,this);}
    TriggerIncreaseDoom(){}
    static TriggerIncreaseDoom prototype;
};

class TriggerIncreaseHorror:public Trigger
{
public:
    Trigger *clone() const{return new TriggerIncreaseHorror(*this);}
    void applyTrigger();
private:
    TriggerIncreaseHorror(Dummy){Trigger::addPrototypeTrigger(TT_INCREASE_HORROR,this);}
    TriggerIncreaseHorror(){}
    static TriggerIncreaseHorror prototype;
};

class TriggerMonsterSurge:public Trigger
{
public:
    Trigger *clone() const{return new TriggerMonsterSurge(*this);}
    void applyTrigger();
private:
    TriggerMonsterSurge(Dummy){Trigger::addPrototypeTrigger(TT_MONSTER_SURGE,this);}
    TriggerMonsterSurge(){}
    static TriggerMonsterSurge prototype;
};


class TriggerGateCancel:public Trigger
{
public:
    Trigger *clone() const{return new TriggerGateCancel(*this);}
    void applyTrigger();
private:
    TriggerGateCancel(Dummy){Trigger::addPrototypeTrigger(TT_GATE_CANCEL,this);}
    TriggerGateCancel(){}
    static TriggerGateCancel prototype;
};

class TriggerGateBurst:public Trigger
{
public:
    Trigger *clone() const{return new TriggerGateBurst(*this);}
    void applyTrigger();
private:
    TriggerGateBurst(Dummy){Trigger::addPrototypeTrigger(TT_GATE_BURST,this);}
    TriggerGateBurst(){}
    static TriggerGateBurst prototype;
};

class TriggerObjectRemove:public Trigger
{
public:
    Trigger *clone() const{return new TriggerObjectRemove(*this);}
    void applyTrigger();
private:
    TriggerObjectRemove(Dummy){Trigger::addPrototypeTrigger(TT_OBJECT_REMOVE,this);}
    TriggerObjectRemove(){}
    static TriggerObjectRemove prototype;
};

class TriggerGateClose:public Trigger
{
public:
    Trigger *clone() const{return new TriggerGateClose(*this);}
    void applyTrigger();
private:
    TriggerGateClose(Dummy){Trigger::addPrototypeTrigger(TT_GATE_CLOSE,this);}
    TriggerGateClose(){}
    static TriggerGateClose prototype;
};

class TriggerGateSeal:public Trigger
{
public:
    Trigger *clone() const{return new TriggerGateSeal(*this);}
    void applyTrigger();
private:
    TriggerGateSeal(Dummy){Trigger::addPrototypeTrigger(TT_GATE_SEAL,this);}
    TriggerGateSeal(){}
    static TriggerGateSeal prototype;
};

class TriggerGetObjectToPlayer:public Trigger
{
public:
    Trigger *clone() const{return new TriggerGetObjectToPlayer(*this);}
    void applyTrigger();
private:
    TriggerGetObjectToPlayer(Dummy){Trigger::addPrototypeTrigger(TT_GET_OBJECT,this);}
    TriggerGetObjectToPlayer(){}
    static TriggerGetObjectToPlayer prototype;
};

class TriggerLostObjectFromPlayer:public Trigger
{
public:
    Trigger *clone() const{return new TriggerLostObjectFromPlayer(*this);}
    void applyTrigger();
private:
    TriggerLostObjectFromPlayer(Dummy){Trigger::addPrototypeTrigger(TT_LOST_OBJECT,this);}
    TriggerLostObjectFromPlayer(){}
    static TriggerLostObjectFromPlayer prototype;
};

class TriggerDecreaseDoom:public Trigger
{
public:
    Trigger *clone() const{return new TriggerDecreaseDoom(*this);}
    void applyTrigger();
private:
    TriggerDecreaseDoom(Dummy){Trigger::addPrototypeTrigger(TT_DECREASE_DOOM,this);}
    TriggerDecreaseDoom(){}
    static TriggerDecreaseDoom prototype;
};

class TriggerDecreaseHorror:public Trigger
{
public:
    Trigger *clone() const{return new TriggerDecreaseHorror(*this);}
    void applyTrigger();
private:
    TriggerDecreaseHorror(Dummy){Trigger::addPrototypeTrigger(TT_DECREASE_HORROR,this);}
    TriggerDecreaseHorror(){}
    static TriggerDecreaseHorror prototype;
};

class TriggerAddObjToCard:public Trigger
{
public:
    Trigger *clone() const{return new TriggerAddObjToCard(*this);}
    void applyTrigger();
private:
    TriggerAddObjToCard(Dummy){Trigger::addPrototypeTrigger(TT_ADD_OBJ_TO_CARD,this);}
    TriggerAddObjToCard(){}
    static TriggerAddObjToCard prototype;
};

class TriggerLoseObjToCard:public Trigger
{
public:
    Trigger *clone() const{return new TriggerLoseObjToCard(*this);}
    void applyTrigger();
private:
    TriggerLoseObjToCard(Dummy){Trigger::addPrototypeTrigger(TT_LOSE_OBJ_TO_CARD,this);}
    TriggerLoseObjToCard(){}
    static TriggerLoseObjToCard prototype;
};


#endif // TRIGGERCOLLECTIONS_H

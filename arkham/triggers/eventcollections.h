#ifndef EVENTCOLLECTIONS_H
#define EVENTCOLLECTIONS_H
#include "triggers/eventobject.h"

class EventGateOpen:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventGateOpen(*this);
    }
private:
    EventGateOpen(Dummy)
    {
        EventObject::addPrototypeEvent(TT_GATE_OPEN,this);
    }
    EventGateOpen()
    {
    }
    static EventGateOpen prototype;

    // EventObject interface
public:
    void iniEventTrigger();
};


class EventObjectAppend:public EventObject
{
public:
    EventObject *clone() const{return new EventObjectAppend(*this);}
    void iniEventTrigger();
private:
    EventObjectAppend(Dummy){EventObject::addPrototypeEvent(TT_OBJECT_APPEND,this);}
    EventObjectAppend(){}
    static EventObjectAppend prototype;
};


class EventMonsterAppend:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventMonsterAppend(*this);
    }
private:
    EventMonsterAppend(Dummy)
    {
        EventObject::addPrototypeEvent(TT_MONSTER_APPEND,this);
    }
    EventMonsterAppend(){}
    static EventMonsterAppend prototype;

    // EventObject interface
public:
    void iniEventTrigger();
};


class EventMonsterMove:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventMonsterMove(*this);
    }
private:
    EventMonsterMove(Dummy)
    {
        EventObject::addPrototypeEvent(TT_MONSTER_MOVE,this);
    }
    EventMonsterMove(){}
    static EventMonsterMove prototype;

    // EventObject interface
public:
    void iniEventTrigger();
};


class EventObjectMove:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventObjectMove(*this);
    }
private:
    EventObjectMove(Dummy)
    {
        EventObject::addPrototypeEvent(TT_OBJECT_MOVE,this);
    }
    EventObjectMove(){}
    static EventObjectMove prototype;
public:
    void iniEventTrigger();
};


class EventSymbolMove:public EventObject
{
public:
    EventObject *clone() const{return new EventSymbolMove(*this);}
    void iniEventTrigger();
private:
    EventSymbolMove(Dummy){EventObject::addPrototypeEvent(TT_SYMBOL_MOVE,this);}
    EventSymbolMove(){}
    static EventSymbolMove prototype;
};

class EventResolveCard:public EventObject
{
public:
    EventObject *clone() const{return new EventResolveCard(*this);}
    void iniEventTrigger();
private:
    EventResolveCard(Dummy){EventObject::addPrototypeEvent(TT_RESOLVE_CARD,this);}
    EventResolveCard(){}
    static EventResolveCard prototype;
};

class EventIncreaseDoom:public EventObject
{
public:
    EventObject *clone() const{return new EventIncreaseDoom(*this);}
    void iniEventTrigger();
private:
    EventIncreaseDoom(Dummy){EventObject::addPrototypeEvent(TT_INCREASE_DOOM,this);}
    EventIncreaseDoom(){}
    static EventIncreaseDoom prototype;
};

class EventMonsterSurge:public EventObject
{
public:
    EventObject *clone() const{return new EventMonsterSurge(*this);}
    void iniEventTrigger();
private:
    EventMonsterSurge(Dummy){EventObject::addPrototypeEvent(TT_MONSTER_SURGE,this);}
    EventMonsterSurge(){}
    static EventMonsterSurge prototype;
};

class EventGateCancel:public EventObject
{
public:
    EventObject *clone() const{return new EventGateCancel(*this);}
    void iniEventTrigger();
private:
    EventGateCancel(Dummy){EventObject::addPrototypeEvent(TT_GATE_CANCEL,this);}
    EventGateCancel(){}
    static EventGateCancel prototype;
};

class EventGateBurst:public EventObject
{
public:
    EventObject *clone() const{return new EventGateBurst(*this);}
    void iniEventTrigger();
private:
    EventGateBurst(Dummy){EventObject::addPrototypeEvent(TT_GATE_BURST,this);}
    EventGateBurst(){}
    static EventGateBurst prototype;
};

class EventGateClose:public EventObject
{
public:
    EventObject *clone() const{return new EventGateClose(*this);}
    void iniEventTrigger();
private:
    EventGateClose(Dummy){EventObject::addPrototypeEvent(TT_GATE_CLOSE,this);}
    EventGateClose(){}
    static EventGateClose prototype;
};

class EventGateSeal:public EventObject
{
public:
    EventObject *clone() const{return new EventGateSeal(*this);}
    void iniEventTrigger();
private:
    EventGateSeal(Dummy){EventObject::addPrototypeEvent(TT_GATE_SEAL,this);}
    EventGateSeal(){}
    static EventGateSeal prototype;
};

class EventObjectRemove:public EventObject
{
public:
    EventObject *clone() const{return new EventObjectRemove(*this);}
    void iniEventTrigger();
private:
    EventObjectRemove(Dummy)
    {EventObject::addPrototypeEvent(TT_OBJECT_REMOVE,this);}
    EventObjectRemove(){}
    static EventObjectRemove prototype;
};

class EventGetObjectToPlayer:public EventObject
{
public:
    EventObject *clone() const{return new EventGetObjectToPlayer(*this);}
    void iniEventTrigger();
private:
    EventGetObjectToPlayer(Dummy)
    {EventObject::addPrototypeEvent(TT_GET_OBJECT,this);}
    EventGetObjectToPlayer(){}
    static EventGetObjectToPlayer prototype;
};

class EventLostObjectFromPlayer:public EventObject
{
public:
    EventObject *clone() const{return new EventLostObjectFromPlayer(*this);}
    void iniEventTrigger();
private:
    EventLostObjectFromPlayer(Dummy)
    {EventObject::addPrototypeEvent(TT_LOST_OBJECT,this);}
    EventLostObjectFromPlayer(){}
    static EventLostObjectFromPlayer prototype;
};

class EventDecreaseDoom:public EventObject
{
public:
    EventObject *clone() const{return new EventDecreaseDoom(*this);}
    void iniEventTrigger();
private:
    EventDecreaseDoom(Dummy)
    {EventObject::addPrototypeEvent(TT_DECREASE_DOOM,this);}
    EventDecreaseDoom(){}
    static EventDecreaseDoom prototype;
};

class EventDecreaseHorror:public EventObject
{
public:
    EventObject *clone() const{return new EventDecreaseHorror(*this);}
    void iniEventTrigger();
private:
    EventDecreaseHorror(Dummy)
    {EventObject::addPrototypeEvent(TT_DECREASE_HORROR,this);}
    EventDecreaseHorror(){}
    static EventDecreaseHorror prototype;
};

class EventAddObjToCard:public EventObject
{
public:
    EventObject *clone() const{return new EventAddObjToCard(*this);}
    void iniEventTrigger();
private:
    EventAddObjToCard(Dummy)
    {EventObject::addPrototypeEvent(TT_ADD_OBJ_TO_CARD,this);}
    EventAddObjToCard(){}
    static EventAddObjToCard prototype;
};

class EventIncreaseHorror:public EventObject
{
public:
    EventObject *clone() const{return new EventIncreaseHorror(*this);}
    void iniEventTrigger();
private:
    EventIncreaseHorror(Dummy)
    {EventObject::addPrototypeEvent(TT_INCREASE_HORROR,this);}
    EventIncreaseHorror(){}
    static EventIncreaseHorror prototype;
};

class EventLoseObjToCard:public EventObject
{
public:
    EventObject *clone() const{return new EventLoseObjToCard(*this);}
    void iniEventTrigger();
private:
    EventLoseObjToCard(Dummy)
    {EventObject::addPrototypeEvent(TT_LOSE_OBJ_TO_CARD,this);}
    EventLoseObjToCard(){}
    static EventLoseObjToCard prototype;
};


/*
class EventGateBurst:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventGateBurst(*this);
    }
private:
    EventGateBurst(Dummy)
    {
        EventObject::addPrototypeEvent(TT_GATE_BURST,this);
    }
    EventGateBurst(){}
    static EventGateBurst prototype;
};

class EventGateClose:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventGateClose(*this);
    }
private:
    EventGateClose(Dummy)
    {
        EventObject::addPrototypeEvent(TT_GATE_CLOSE,this);
    }
    EventGateClose(){}
    static EventGateClose prototype;
};

class EventGateSeal:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventGateSeal(*this);
    }
private:
    EventGateSeal(Dummy)
    {
        EventObject::addPrototypeEvent(TT_GATE_SEAL,this);
    }
    EventGateSeal(){}
    static EventGateSeal prototype;
};



class EventLostObject:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventLostObject(*this);
    }
private:
    EventLostObject(Dummy)
    {
        EventObject::addPrototypeEvent(TT_LOST_OBJECT,this);
    }
    EventLostObject(){}
    static EventLostObject prototype;
};

class EventGetObject:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventGetObject(*this);
    }
private:
    EventGetObject(Dummy)
    {
        EventObject::addPrototypeEvent(TT_GET_OBJECT,this);
    }
    EventGetObject(){}
    static EventGetObject prototype;
};




class EventObjectDestroy:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventObjectDestroy(*this);
    }
private:
    EventObjectDestroy(Dummy)
    {
        EventObject::addPrototypeEvent(TT_OBJECT_DESTROY,this);
    }
    EventObjectDestroy(){}
    static EventObjectDestroy prototype;
};

class EventIncreaseHorror:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventIncreaseHorror(*this);
    }
private:
    EventIncreaseHorror(Dummy)
    {
        EventObject::addPrototypeEvent(TT_INCREASE_HORROR,this);
    }
    EventIncreaseHorror(){}
    static EventIncreaseHorror prototype;
};

class EventDecreaseHorror:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventDecreaseHorror(*this);
    }
private:
    EventDecreaseHorror(Dummy)
    {
        EventObject::addPrototypeEvent(TT_DECREASE_HORROR,this);
    }
    EventDecreaseHorror(){}
    static EventDecreaseHorror prototype;
};

class EventIncreaseDoom:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventIncreaseDoom(*this);
    }
private:
    EventIncreaseDoom(Dummy)
    {
        EventObject::addPrototypeEvent(TT_INCREASE_DOOM,this);
    }
    EventIncreaseDoom(){}
    static EventIncreaseDoom prototype;
};

class EventDecreaseDoom:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventDecreaseDoom(*this);
    }
private:
    EventDecreaseDoom(Dummy)
    {
        EventObject::addPrototypeEvent(TT_DECREASE_DOOM,this);
    }
    EventDecreaseDoom(){}
    static EventDecreaseDoom prototype;
};



class EventDevoured:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventDevoured(*this);
    }
private:
    EventDevoured(Dummy)
    {
        EventObject::addPrototypeEvent(TT_DEVOURED,this);
    }
    EventDevoured(){}
    static EventDevoured prototype;
};

class EventNextPlayer:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventNextPlayer(*this);
    }
private:
    EventNextPlayer(Dummy)
    {
        EventObject::addPrototypeEvent(TT_NEXT_PLAYER,this);
    }
    EventNextPlayer(){}
    static EventNextPlayer prototype;
};

class EventNewProcess:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventNewProcess(*this);
    }
private:
    EventNewProcess(Dummy)
    {
        EventObject::addPrototypeEvent(TT_NEW_PROCESS,this);
    }
    EventNewProcess(){}
    static EventNewProcess prototype;
};

class EventNewRumors:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventNewRumors(*this);
    }
private:
    EventNewRumors(Dummy)
    {
        EventObject::addPrototypeEvent(TT_NEW_RUMORS,this);
    }
    EventNewRumors(){}
    static EventNewRumors prototype;
};

class EventRoll:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventRoll(*this);
    }
private:
    EventRoll(Dummy)
    {
        EventObject::addPrototypeEvent(TT_ROLL,this);
    }
    EventRoll(){}
    static EventRoll prototype;
};

class EventAddObjToCard:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventAddObjToCard(*this);
    }
private:
    EventAddObjToCard(Dummy)
    {
        EventObject::addPrototypeEvent(TT_ADD_OBJ_TO_CARD,this);
    }
    EventAddObjToCard(){}
    static EventAddObjToCard prototype;
};

class EventLoseObjToCard:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventLoseObjToCard(*this);
    }
private:
    EventLoseObjToCard(Dummy)
    {
        EventObject::addPrototypeEvent(TT_LOSE_OBJ_TO_CARD,this);
    }
    EventLoseObjToCard(){}
    static EventLoseObjToCard prototype;
};



class EventNextPhase:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventNextPhase(*this);
    }
private:
    EventNextPhase(Dummy)
    {
        EventObject::addPrototypeEvent(TT_NEXT_PHASE,this);
    }
    EventNextPhase(){}
    static EventNextPhase prototype;
};

class EventSlayMonster:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventSlayMonster(*this);
    }
private:
    EventSlayMonster(Dummy)
    {
        EventObject::addPrototypeEvent(TT_SLAY_MONSTER,this);
    }
    EventSlayMonster(){}
    static EventSlayMonster prototype;
};

class EventStartAncientBattle:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventStartAncientBattle(*this);
    }
private:
    EventStartAncientBattle(Dummy)
    {
        EventObject::addPrototypeEvent(TT_START_ANCIENT_BATTLE,this);
    }
    EventStartAncientBattle(){}
    static EventStartAncientBattle prototype;
};

class EventSkillCheck:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventSkillCheck(*this);
    }
private:
    EventSkillCheck(Dummy)
    {
        EventObject::addPrototypeEvent(TT_SKILL_CHECK,this);
    }
    EventSkillCheck(){}
    static EventSkillCheck prototype;
};

class EventReadingSpell:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventReadingSpell(*this);
    }
private:
    EventReadingSpell(Dummy)
    {
        EventObject::addPrototypeEvent(TT_READING_SPELL,this);
    }
    EventReadingSpell(){}
    static EventReadingSpell prototype;
};

class EventUseSpecials:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventUseSpecials(*this);
    }
private:
    EventUseSpecials(Dummy)
    {
        EventObject::addPrototypeEvent(TT_USE_SPECIAL,this);
    }
    EventUseSpecials(){}
    static EventUseSpecials prototype;
};

class EventLostInTime:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventLostInTime(*this);
    }
private:
    EventLostInTime(Dummy)
    {
        EventObject::addPrototypeEvent(TT_LOST_IN_TIME,this);
    }
    EventLostInTime(){}
    static EventLostInTime prototype;
};

class EventInsane:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventInsane(*this);
    }
private:
    EventInsane(Dummy)
    {
        EventObject::addPrototypeEvent(TT_INSANE,this);
    }
    EventInsane(){}
    static EventInsane prototype;
};

class EventUnconscious:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventUnconscious(*this);
    }
private:
    EventUnconscious(Dummy)
    {
        EventObject::addPrototypeEvent(TT_UNCONSCIOUS,this);
    }
    EventUnconscious(){}
    static EventUnconscious prototype;
};

class EventArrested:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventArrested(*this);
    }
private:
    EventArrested(Dummy)
    {
        EventObject::addPrototypeEvent(TT_ARRESTED,this);
    }
    EventArrested(){}
    static EventArrested prototype;
};

class EventDelayed:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventDelayed(*this);
    }
private:
    EventDelayed(Dummy)
    {
        EventObject::addPrototypeEvent(TT_DELAYED,this);
    }
    EventDelayed(){}
    static EventDelayed prototype;
};

class EventBlessing:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventBlessing(*this);
    }
private:
    EventBlessing(Dummy)
    {
        EventObject::addPrototypeEvent(TT_BLESSING,this);
    }
    EventBlessing(){}
    static EventBlessing prototype;
};

class EventCursed:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventCursed(*this);
    }
private:
    EventCursed(Dummy)
    {
        EventObject::addPrototypeEvent(TT_CURSED,this);
    }
    EventCursed(){}
    static EventCursed prototype;
};

class EventMovingStart:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventMovingStart(*this);
    }
private:
    EventMovingStart(Dummy)
    {
        EventObject::addPrototypeEvent(TT_MOVING_START,this);
    }
    EventMovingStart(){}
    static EventMovingStart prototype;
};

class EventMovingStop:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventMovingStop(*this);
    }
private:
    EventMovingStop(Dummy)
    {
        EventObject::addPrototypeEvent(TT_MOVING_STOP,this);
    }
    EventMovingStop(){}
    static EventMovingStop prototype;
};

class EventTrade:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventTrade(*this);
    }
private:
    EventTrade(Dummy)
    {
        EventObject::addPrototypeEvent(TT_TRADE,this);
    }
    EventTrade(){}
    static EventTrade prototype;
};

class EventDiscardObject:public EventObject
{
public:
    EventObject *clone() const
    {
        return new EventDiscardObject(*this);
    }
private:
    EventDiscardObject(Dummy)
    {
        EventObject::addPrototypeEvent(TT_DISCARD_OBJECT,this);
    }
    EventDiscardObject(){}
    static EventDiscardObject prototype;
};

*/

#endif // EVENTCOLLECTIONS_H

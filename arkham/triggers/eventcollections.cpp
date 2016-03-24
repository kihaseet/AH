#include "eventcollections.h"

EventAddObjToCard EventAddObjToCard::prototype = EventAddObjToCard(Dummy());
EventDecreaseDoom EventDecreaseDoom::prototype = EventDecreaseDoom(Dummy());
EventDecreaseHorror EventDecreaseHorror::prototype = EventDecreaseHorror(Dummy());
EventGateBurst EventGateBurst::prototype = EventGateBurst(Dummy());
EventGateCancel EventGateCancel::prototype = EventGateCancel(Dummy());
EventGateClose EventGateClose::prototype = EventGateClose(Dummy());
EventGateSeal EventGateSeal::prototype = EventGateSeal(Dummy());
EventGateOpen EventGateOpen::prototype = EventGateOpen(Dummy());
EventGetObjectToPlayer EventGetObjectToPlayer::prototype = EventGetObjectToPlayer(Dummy());
EventIncreaseDoom EventIncreaseDoom::prototype = EventIncreaseDoom(Dummy());
EventIncreaseHorror EventIncreaseHorror::prototype = EventIncreaseHorror(Dummy());
EventLoseObjToCard EventLoseObjToCard::prototype = EventLoseObjToCard(Dummy());
EventLostObjectFromPlayer EventLostObjectFromPlayer::prototype = EventLostObjectFromPlayer(Dummy());
EventMonsterAppend EventMonsterAppend::prototype = EventMonsterAppend(Dummy());
EventMonsterMove EventMonsterMove::prototype = EventMonsterMove(Dummy());
EventMonsterSurge EventMonsterSurge::prototype = EventMonsterSurge(Dummy());
EventObjectAppend EventObjectAppend::prototype = EventObjectAppend(Dummy());
EventObjectMove EventObjectMove::prototype = EventObjectMove(Dummy());
EventObjectRemove EventObjectRemove::prototype = EventObjectRemove(Dummy());
EventResolveCard EventResolveCard::prototype = EventResolveCard(Dummy());
EventSymbolMove EventSymbolMove::prototype = EventSymbolMove(Dummy());


/*

EventArrested EventArrested::prototype = EventArrested(Dummy());
EventBlessing EventBlessing::prototype = EventBlessing(Dummy());
EventCursed EventCursed::prototype = EventCursed(Dummy());

EventDelayed EventDelayed::prototype = EventDelayed(Dummy());
EventDevoured EventDevoured::prototype = EventDevoured(Dummy());
EventDiscardObject EventDiscardObject::prototype = EventDiscardObject(Dummy());
EventIncreaseHorror EventIncreaseHorror::prototype = EventIncreaseHorror(Dummy());
EventInsane EventInsane::prototype = EventInsane(Dummy());

EventLostInTime EventLostInTime::prototype = EventLostInTime(Dummy());
EventMovingStart EventMovingStart::prototype = EventMovingStart(Dummy());
EventMovingStop EventMovingStop::prototype = EventMovingStop(Dummy());
EventNewProcess EventNewProcess::prototype = EventNewProcess(Dummy());
EventNewRumors EventNewRumors::prototype = EventNewRumors(Dummy());
EventNextPhase EventNextPhase::prototype = EventNextPhase(Dummy());
EventNextPlayer EventNextPlayer::prototype = EventNextPlayer(Dummy());
EventObjectDestroy EventObjectDestroy::prototype = EventObjectDestroy(Dummy());
EventReadingSpell EventReadingSpell::prototype = EventReadingSpell(Dummy());
EventRoll EventRoll::prototype = EventRoll(Dummy());
EventSkillCheck EventSkillCheck::prototype = EventSkillCheck(Dummy());
EventSlayMonster EventSlayMonster::prototype = EventSlayMonster(Dummy());
EventStartAncientBattle EventStartAncientBattle::prototype = EventStartAncientBattle(Dummy());
EventTrade EventTrade::prototype = EventTrade(Dummy());
EventUnconscious EventUnconscious::prototype = EventUnconscious(Dummy());
EventUseSpecials EventUseSpecials::prototype = EventUseSpecials(Dummy());
*/


void EventGateOpen::iniEventTrigger()
{
    Q_ASSERT(target != 0);
    Q_ASSERT(who != 0);
    if(static_cast<location*>(target)->getSeal() != 0)                       //если в локации есть печать
        appendTrigger(Trigger::createTrigger(TT_GATE_CANCEL, who,target));  //врата не открываются
    else if ((static_cast<location*>(target)->getGate()==0))  {              //если в локации нет врат
        appendTrigger(Trigger::createTrigger(TT_GATE_OPEN, who,target));    //врата открываются
        appendTrigger(Trigger::createTrigger(TT_INCREASE_DOOM, who,target));//растет безысходность
    }
    else                                                                    //если в локации нет печати и есть врата
        appendTrigger(Trigger::createTrigger(TT_MONSTER_SURGE,0,target));   //происходит наплыв
}

void EventObjectAppend::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_OBJECT_APPEND,who,target));
}

void EventMonsterAppend::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_MONSTER_APPEND,who,target));
}

void EventMonsterMove::iniEventTrigger()
{
    Q_ASSERT((commTarget == MARK_WHITE) || (commTarget == MARK_BLACK) || (commTarget == MARK_FLY));
    appendTrigger(Trigger::createTrigger(TT_MONSTER_MOVE,who,target,commTarget));
}

void EventObjectMove::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_OBJECT_MOVE,who,target));
}

void EventSymbolMove::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_SYMBOL_MOVE,who,target,commTarget));
    foreach (location* loc, Data::getData()->locationList) {
        foreach (Monster* monster, loc->getMonsters()) {
            if(monster->getMonsterSymbol()==commWho){
                appendTrigger(Trigger::createTrigger(TT_MONSTER_MOVE,monster,loc,commTarget));
            }
        }
    }
}

void EventResolveCard::iniEventTrigger()        //тип карты записан в commTarget
{
    appendTrigger(Trigger::createTrigger(TT_RESOLVE_CARD,who,target));
}

void EventIncreaseDoom::iniEventTrigger()   //who - указатель на жетон, по умолчанию кладется на трек безысходности древнего
{
    appendTrigger(Trigger::createTrigger(TT_INCREASE_DOOM,who,target));
}

void EventMonsterSurge::iniEventTrigger()   //target - локация, откуда начинается наплыв
{
    appendTrigger(Trigger::createTrigger(TT_MONSTER_SURGE,who,target));
}

void EventGateCancel::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_GATE_CANCEL,who,target));
}

void EventGateBurst::iniEventTrigger()
{
    Q_ASSERT(target!=0);
    IObject* seal = 0;
    if((seal = static_cast<location*>(target)->getSeal()) != 0)  {        //если в локации есть печать
        appendTrigger(Trigger::createTrigger(TT_OBJECT_REMOVE, seal));    //удаляем печать
        appendTrigger(Trigger::createTrigger(TT_GATE_OPEN, who,target));  //врата открываются
    }
    else if ((static_cast<location*>(target)->getGate()==0))                //если в локации нет врат
        appendTrigger(Trigger::createTrigger(TT_GATE_OPEN, who,target));    //врата открываются
    else                                                                    //если в локации нет печати и есть врата
        appendTrigger(Trigger::createTrigger(TT_MONSTER_SURGE,0,target));   //происходит наплыв

}

void EventObjectRemove::iniEventTrigger()
{
    Q_ASSERT(target!=0);
    Q_ASSERT(who!=0);
    appendTrigger(Trigger::createTrigger(TT_OBJECT_REMOVE,who,target));
}

void EventGateClose::iniEventTrigger()
{
    Q_ASSERT(target!=0);
    appendTrigger(Trigger::createTrigger(TT_GATE_CLOSE,who,target));    //таргет - ворота, who - игрок,
    //если who 0, врата возвращаются в пул
    foreach (location* Loc, Data::getData()->locationList) {            //убираем монстров с карты в пул
        foreach (Monster* monster, Loc->getMonsters()) {
            if(monster->getMonsterSymbol() == static_cast<Gate*>(target)->getMythosSymbol())
                appendTrigger(Trigger::createTrigger(TT_OBJECT_REMOVE,monster));
        }
    }
    foreach (Monster* monster, Data::getData()->sky->getMonsters()) {   //убираем монстров с неба в пул
        if(monster->getMonsterSymbol() == static_cast<Gate*>(target)->getMythosSymbol())
            appendTrigger(Trigger::createTrigger(TT_OBJECT_REMOVE,monster));
    }
    foreach (Monster* monster, Data::getData()->outskirts->getMonsters()) { //убираем монстров с окраин в пул
        if(monster->getMonsterSymbol() == static_cast<Gate*>(target)->getMythosSymbol())
            appendTrigger(Trigger::createTrigger(TT_OBJECT_REMOVE,monster));
    }
}

void EventGateSeal::iniEventTrigger()
{
    Q_ASSERT(who!=0);
    appendTrigger(Trigger::createTrigger(TT_GATE_SEAL,who));        //who - локация, на которую кладется печать
}

void EventGetObjectToPlayer::iniEventTrigger() //who - игрок, target - карта или жетон
{
    Q_ASSERT(who != 0);
    Q_ASSERT(target != 0);
    appendTrigger(Trigger::createTrigger(TT_GET_OBJECT,who,target));
}

void EventLostObjectFromPlayer::iniEventTrigger()//who - игрок, target - карта или жетон
{
    Q_ASSERT(who != 0);
    Q_ASSERT(target != 0);
    appendTrigger(Trigger::createTrigger(TT_LOST_OBJECT,who,target));
}

void EventDecreaseDoom::iniEventTrigger()
{
     appendTrigger(Trigger::createTrigger(TT_DECREASE_DOOM,who,target));
}

void EventDecreaseHorror::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_DECREASE_HORROR));
}

void EventAddObjToCard::iniEventTrigger()   //who - добавляемый объект, target - на какую карту кладется
{
    appendTrigger(Trigger::createTrigger(TT_ADD_OBJ_TO_CARD,who,target));
}

void EventIncreaseHorror::iniEventTrigger()
{
    appendTrigger(Trigger::createTrigger(TT_INCREASE_HORROR));
}

void EventLoseObjToCard::iniEventTrigger() //who - удаляемый объект
{
    appendTrigger(Trigger::createTrigger(TT_LOSE_OBJ_TO_CARD,who));
}

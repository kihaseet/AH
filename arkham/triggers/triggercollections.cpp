#include "triggercollections.h"

TriggerAddObjToCard TriggerAddObjToCard::prototype = TriggerAddObjToCard(Dummy());
TriggerGateBurst TriggerGateBurst::prototype = TriggerGateBurst(Dummy());
TriggerGateCancel TriggerGateCancel::prototype = TriggerGateCancel(Dummy());
TriggerGateClose TriggerGateClose::prototype = TriggerGateClose(Dummy());
TriggerGateOpen TriggerGateOpen::prototype = TriggerGateOpen(Dummy());
TriggerGateSeal TriggerGateSeal::prototype = TriggerGateSeal(Dummy());
TriggerObjectAppend TriggerObjectAppend::prototype = TriggerObjectAppend(Dummy());
TriggerMonsterAppend TriggerMonsterAppend::prototype = TriggerMonsterAppend(Dummy());
TriggerMonsterMove TriggerMonsterMove::prototype = TriggerMonsterMove(Dummy());
TriggerObjectMove TriggerObjectMove::prototype = TriggerObjectMove(Dummy());
TriggerObjectRemove TriggerObjectRemove::prototype = TriggerObjectRemove(Dummy());
TriggerSymbolMove TriggerSymbolMove::prototype = TriggerSymbolMove(Dummy());
TriggerMonsterMoveToOutskirts TriggerMonsterMoveToOutskirts::prototype = TriggerMonsterMoveToOutskirts(Dummy());
TriggerResolveCard TriggerResolveCard::prototype = TriggerResolveCard(Dummy());
TriggerIncreaseDoom TriggerIncreaseDoom::prototype = TriggerIncreaseDoom(Dummy());
TriggerMonsterSurge TriggerMonsterSurge::prototype = TriggerMonsterSurge(Dummy());
TriggerGetObjectToPlayer TriggerGetObjectToPlayer::prototype = TriggerGetObjectToPlayer(Dummy());
TriggerLostObjectFromPlayer TriggerLostObjectFromPlayer::prototype = TriggerLostObjectFromPlayer(Dummy());
TriggerDecreaseHorror TriggerDecreaseHorror::prototype = TriggerDecreaseHorror(Dummy());
TriggerDecreaseDoom TriggerDecreaseDoom::prototype = TriggerDecreaseDoom(Dummy());
TriggerLoseObjToCard TriggerLoseObjToCard::prototype = TriggerLoseObjToCard(Dummy());

void TriggerGateOpen::applyTrigger()
{
    qDebug()<<"Trigger: "<<"Create new Gate in" << target->name << "to" << object->name;

    Data::getData()->countGates++;
    EventObject::createEvent(TT_OBJECT_APPEND,this->object,this->target)->runEvent();
    EventObject::createEvent(TT_INCREASE_DOOM,Data::getData()->getDoomFromCup(),this->target)->runEvent();
    EventObject::createEvent(TT_MONSTER_APPEND,Data::getData()->getRandemFreeMonster(),this->target)->runEvent();
}

void TriggerObjectAppend::applyTrigger()
{
    static_cast<Token*>(object)->placeToken(target);
    qDebug()<<"Trigger: "<<"append Object ID"<<object->getIObjectID()<<object->name<<"to map in ID"<<target->getIObjectID()<<target->name;
}



void TriggerMonsterAppend::applyTrigger()
{
    Data::getData()->countMonster++;
    EventObject *t = EventObject::createEvent(TT_OBJECT_APPEND,this->object,this->target);
    qDebug()<<"Trigger: "<<"Append" << object->name << "to" << target->name;
    t->runEvent();
}

void TriggerMonsterMove::applyTrigger()
{
    Q_ASSERT(object != 0);
    Q_ASSERT (paramType==MARK_BLACK || paramType == MARK_WHITE || paramType == MARK_FLY);
    static_cast<Monster*>(object)->MonsterMove(paramType);
    qDebug()<<"Trigger: "<<"Monster" << object->name <<"move";//<< target->name;
    //t->runEvent();
}

void TriggerObjectMove::applyTrigger()
{

    static_cast<Token*>(object)->moveToken(target);
    qDebug()<<"Trigger: "<<" move Object ID"<<object->getIObjectID() << object->name <<"to"<< target->getIObjectID()<<target->name;
}

void TriggerSymbolMove::applyTrigger()
{
    qDebug()<<"Trigger: move Symbol"<<static_cast<int>(paramType);
}

void TriggerMonsterMoveToOutskirts::applyTrigger()
{
    qDebug()<<"Trigger: move"<<object->name<<"to Outskirts";
    static_cast<Token*>(object)->moveToken(Data::getData()->outskirts);
}

void TriggerResolveCard::applyTrigger()
{
    qDebug()<<"Trigger: resolve card";
    static_cast<Mythos*>(object)->ResolveEvents();
}

void TriggerIncreaseDoom::applyTrigger()
{
    qDebug()<<"Trigger: increase doom";
    Data::getData()->appendTokenDoomTrack(static_cast<Token*>(object));
    //TODO добавить жетон на карту древнего
}

location* getLessMonsterLocation(IObject* target){  //функция возвращает локацию с вратами, на которой меньше монстров, чем на переданной в target
    //и target, если она - наименьшая
    Q_ASSERT(target!=0);
    QList<location*> lslGates;  //список всех локаций с открытыми вратами
    foreach (location* loc, Data::getData()->locationList) {
        if(loc->getGate() != 0)
            lslGates.append(loc);
    }
    Q_ASSERT(!lslGates.isEmpty());                  //мы должны получить хотя бы одну локацию с вратами, если ее нет - вылет
    if(lslGates.isEmpty()) return 0;
    location* lessMonster = static_cast<location*>(target);
    foreach (location* loc, lslGates) {
        if(loc == target) continue;
        if(loc->getMonsters().count() < lessMonster->getMonsters().count())
            lessMonster = loc;
    }
    return lessMonster;
}

void TriggerMonsterSurge::applyTrigger()
{
    qDebug()<<"Trigger: Monster Surge in"<<target->name;
    location* targetLocation = static_cast<location*>(target);
    int countPlayer = Data::getData()->playerlist.count();
    int countGates = Data::getData()->countGates;
    int moreValue = 0;
    if(countPlayer > countGates){
        moreValue = countPlayer;
    } else moreValue = countGates;

    Q_ASSERT(moreValue>0);  //если и то и другое равно 0 или меньше, то вылет с ошибкой
    QList<location*> lslGates;  //список всех локаций с открытыми вратами
    foreach (location* loc, Data::getData()->locationList) {
        if(loc->getGate() != 0)
            lslGates.append(loc);
    }
    foreach (location* loc, lslGates) {
        if(loc == targetLocation) continue;
        while(loc->getMonsters().count() > targetLocation->getMonsters().count()){  //пока в локации больше монстров, чем в target, добавляем монстров в target
            EventObject::createEvent(TT_MONSTER_APPEND,Data::getData()->getRandemFreeMonster(),target)->runEvent();
            moreValue--;
            if(moreValue == 0) return;      //если монстры в наплыве кончились, выходим из функции
        }
    }
    location* tmpLoc = 0;
    //пока монстры наплыва не кончились, раскидываем их по локациям, в которых их меньше, чем в исходной
    //потом добавляем одного монстра на исходную
    while(moreValue > 0){
        while ((tmpLoc = getLessMonsterLocation(target)) != target){
            EventObject::createEvent(TT_MONSTER_APPEND,Data::getData()->getRandemFreeMonster(),tmpLoc)->runEvent();
            moreValue--;
            if(moreValue == 0) return;      //если монстры в наплыве кончились, выходим из функции
        }
        EventObject::createEvent(TT_MONSTER_APPEND,Data::getData()->getRandemFreeMonster(),target)->runEvent();
        moreValue--;
    }
}


void TriggerGateCancel::applyTrigger()
{
    qDebug()<<"Trigger: gate open cancel!";
}

void TriggerGateBurst::applyTrigger()
{
    qDebug()<<"Trigger: Gate Burst in" << target->name << "to" << object->name;
    IObject* seal = 0;
    if((seal = static_cast<location*>(target)->getSeal()) != 0)
        EventObject::createEvent(TT_OBJECT_REMOVE,seal,target)->runEvent();
    else
        EventObject::createEvent(TT_INCREASE_DOOM,Data::getData()->getDoomFromCup(),this->target)->runEvent();
    Data::getData()->countGates++;

    EventObject::createEvent(TT_OBJECT_APPEND,this->object,this->target)->runEvent();
    EventObject::createEvent(TT_MONSTER_APPEND,Data::getData()->getRandemFreeMonster(),this->target)->runEvent();

    //добавить движение летающих монстров независимо от их движения

}

void TriggerObjectRemove::applyTrigger()
{
    static_cast<location*>(target)->tokenPool.removeOne(static_cast<Token*>(object));
    qDebug()<<"Trigger: "<<"remove Object ID"<<object->getIObjectID()<<object->name<<"to map in ID"<<target->getIObjectID()<<target->name;
}

void TriggerGateClose::applyTrigger()
{
    qDebug()<<"Trigger: close gate to"<<target->name<<"in"<<static_cast<Token*>(target)->place->name;
    static_cast<Token*>(target)->removeToken();
    if(object == 0)   {              //если врата просто закрыты
        Data::getData()->gatePool.append(static_cast<Gate*>(target));
    }

    //TODO добавить если закрыты игроком перенос врат ему в трофеи
}

void TriggerGateSeal::applyTrigger()
{
    Q_ASSERT(object != 0);
    //вставить проверку на наличие врат в локации
    qDebug()<<"Trigger: seal gate in ID"<<object->name;
    Token* seal;
    if((seal = Data::getData()->getElderSignFromCup()) != 0) {    //если свободных жетонов больше нет, то просыпается древний
        static_cast<location*>(object)->tokenPool.append(seal);
    }

    //TODO проверка на условия победы, возможно, отдельным триггером
}

void TriggerGetObjectToPlayer::applyTrigger()
{
    Q_ASSERT(object != 0);
    Q_ASSERT(target != 0);
    qDebug()<<"Trigger: TriggerGetObjectToPlayer"<<target->getIObjectID();
    static_cast<investigator*>(object)->appendObjectToInventory(target);
}

void TriggerLostObjectFromPlayer::applyTrigger()
{
    Q_ASSERT(object != 0);
    Q_ASSERT(target != 0);
    qDebug()<<"Trigger: TriggerLostObjectFromPlayer";
    static_cast<investigator*>(object)->removeObjectFromInventory(target);
    Data::getData()->returnObjectToDeck(object);
}

void TriggerDecreaseDoom::applyTrigger()
{
    Data::getData()->removeLastTokenDoomTrack();
}

void TriggerDecreaseHorror::applyTrigger()
{
    if(Data::getData()->currentHorror > 0) Data::getData()->currentHorror--;
}

void TriggerIncreaseHorror::applyTrigger()
{
    if(Data::getData()->currentHorror < 10) Data::getData()->currentHorror++;
    //TODO добавить событие на закрытие магазинов и удаление союзника из игры
}

void TriggerAddObjToCard::applyTrigger()
{
    Q_ASSERT(object != 0);
    Q_ASSERT(target != 0);
    object->appendToPlace(target);
}

void TriggerLoseObjToCard::applyTrigger()
{
    Q_ASSERT(object != 0);
    object->removeFromPlace();
}

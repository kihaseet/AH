#include "data.h"

void Data::DestroyData()
{
    if (m_instData) {
        delete m_instData;
        m_instData = NULL;
    }
}

Data::Data()
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
}

Data *Data::getData()
{
    if(!m_instData) m_instData = new Data;
    return m_instData;
}

Gate *Data::getRandomFreeGate()
{
    Q_ASSERT(!gatePool.isEmpty());
    if(gatePool.isEmpty()) return NULL;
    int pos = qrand()%gatePool.count();

    Gate* gate = *(gatePool.begin() + pos);
    gatePool.removeAll(gate);
    return gate;
}

Monster *Data::getRandemFreeMonster()
{
    Q_ASSERT(!monsterPool.isEmpty());
    if(monsterPool.isEmpty()) return NULL;
    int pos = qrand()%monsterPool.count();

    Monster* monster = *(monsterPool.begin() + pos);
    monsterPool.removeAll(monster);
    return monster;
}

Mythos *Data::getUpperMythos()
{
    Q_ASSERT(!MythosDeck.isEmpty());
    if(MythosDeck.isEmpty()) return NULL;

    Mythos* mythos = MythosDeck.takeFirst();    //берем верхнюю карту мифа (в начале списка)
    MythosDeck.append(mythos);                  //помещаем ее в конец списка
    return mythos;                              //возвращаем указатель на нее
}

Card *Data::getUpperCommonItem()
{
    Q_ASSERT(!deckCommonItems.isEmpty());
    if(deckCommonItems.isEmpty()) return 0;

    return deckCommonItems.takeFirst();

}

void Data::returnObjectToDeck(IObject* object)
{
    Q_ASSERT(object != 0);
    if(object->getObjectType() == CARD_ITEM) {
        Card* card = static_cast<Card*>(object);
        if(card->getCardType() == CT_COMMON)
            deckCommonItems.append(card);
        else if (card->getCardType() == CT_UNIQUE)
            deckUniqueItems.append(card);
        //...TODO для всех колод карт
    }
    else if(object->getObjectType() == TOKEN_CLUE)
        cupClueToken.append(static_cast<Token*>(object));
    else if(object->getObjectType() == TOKEN_POWER)
        cupPowerToken.append(static_cast<Token*>(object));
}

void Data::insertGlobalMonsterList(Monster *monster)
{
    globalMonsterList.insert(monster->getIObjectID(),monster);
    monsterPool.append(monster);
}

void Data::removeGlobalMonsterList(Monster *monster)
{
    globalMonsterList.remove(monster->getIObjectID());
    monsterPool.removeAll(monster);
    delete monster;
}

void Data::insertGlobalGateList(Gate *gate)
{
    globalGateList.insert(gate->getIObjectID(),gate);
    gatePool.append(gate);
}

void Data::removeGlobalGateList(Gate *gate)
{
    globalGateList.remove(gate->getIObjectID());
    gatePool.removeAll(gate);
    delete gate;
}

void Data::insertGlobalMythosDeck(Mythos *mythos)
{
    globalMythosDeck.insert(mythos->getIObjectID(),mythos);
    MythosDeck.append(mythos);
}

void Data::removeGlobalMythosDeck(Mythos *mythos)
{
    globalMythosDeck.remove(mythos->getIObjectID());
    MythosDeck.removeAll(mythos);
    delete mythos;
}

void Data::InitializeGameData()
{
    outskirts = new location("Outskirts",-1,true,true);
    outskirts->setObjectType(MAP_OUTSKIRTS);
    sky = new location("Sky",-1,true,true);
    sky->setObjectType(MAP_SKY);

    limitGates = 7;
    limitMonster = 1;
    limitOutskirts = 2;
    countGates = 0;
    countMonster = 0;
    countOutskirts = 0;

    for (int i=0;i<16;i++){
        setDoomToCup(new Token("Doom",TOKEN_DOOM));
    }

    locationList.append(new location("Woods",9,false,false));
    locationList.append(new location("Uptown",9,false,true));
    getLocationByName("Woods")->Black = getLocationByName("Uptown");
    getLocationByName("Woods")->White = getLocationByName("Uptown");

    insertGlobalGateList(new Gate("Abyss"));
    insertGlobalGateList(new Gate("Dreamland"));

    insertGlobalMonsterList(new MonsterCultist());
    insertGlobalMonsterList(new MonsterStarspawn());
    //insertGlobalMonsterList(new Monster("Maniac",MARK_RHOMB));


    deckCommonItems.append(new Common18Derringer());
    deckCommonItems.append(new Common18Derringer());
    std::random_shuffle(deckCommonItems.begin(),deckCommonItems.end());

    Mythos* myth = new Mythos("In other Space");
    myth->appendEventToResolveList(EventObject::createEvent(TT_GATE_BURST,Data::getRandomFreeGate(),Data::getLocationByName("Woods")));
    myth->appendEventToResolveList(EventObject::createEvent(TT_SYMBOL_MOVE,MARK_MOON,MARK_WHITE));
    myth->appendEventToResolveList(EventObject::createEvent(TT_SYMBOL_MOVE,MARK_PLUS,MARK_BLACK));
    insertGlobalMythosDeck(myth);

    std::random_shuffle(MythosDeck.begin(),MythosDeck.end());

    Trigger* tr = Trigger::createConditionTrigger(TT_MONSTER_OUTSKIRTS,
                                                  TT_MONSTER_APPEND,
                                                  true,
                                                  new ConditionsCountMonsterOver(limitMonster));
    triggerPool.append(tr);

}

void Data::appendTokenDoomTrack(Token *token)
{
    DoomTrack.append(token);
}

void Data::removeLastTokenDoomTrack()
{
    if(!DoomTrack.isEmpty()) cupDoomToken.append(DoomTrack.takeLast());
}

Token *Data::getDoomFromCup()
{
    if(!cupDoomToken.isEmpty()) return cupDoomToken.takeLast();
    return 0;
}

void Data::setDoomToCup(Token *token)
{
    cupDoomToken.append(token);
}

Token *Data::getElderSignFromCup()
{
    if(!cupDoomToken.isEmpty()) {
        Token* token = cupDoomToken.takeLast();
        token->setObjectType(TOKEN_ELDER_SIGN);
        token->name = "Elder sign";
        return token;
    }

    return 0;
}

void Data::setElderSignToCup(Token *token)
{
    token->name = "Doom";
    token->setObjectType(TOKEN_DOOM);
    cupDoomToken.append(token);
}


location *Data::getLocationByName(QString name)
{
    if(name == "Outskirts")
        return outskirts;
    Q_ASSERT(!locationList.isEmpty());
    foreach (location* Loc, locationList) {
        if(Loc->name == name) return Loc;
    }
    Q_ASSERT(false);        //если локация по имени не найдена
    return NULL;
}

location *Data::findLocationContain(Token *object)
{
    foreach (location* Loc, locationList) {
        if(Loc->tokenPool.contains(object))
            return Loc;
    }
    if(outskirts->tokenPool.contains(object))
        return outskirts;
    Q_ASSERT(false);        //если искомая локация не найдена
    return NULL;
}

QList<investigator *> Data::getPlayersOnStreets()
{
    QList<investigator*> targets;
    foreach (investigator* player, Data::getData()->playerlist.keys()) {
        if(static_cast<location*>(player->place)->getIsStreet()){
            targets.append(player);
        }
    }
    return targets;
}

Data* Data::m_instData = NULL;

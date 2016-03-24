#include "monster.h"
#include "data.h"

MONSTER Monster::getMonsterType() const
{
    return monsterType;
}

void Monster::setMonsterType(const MONSTER &value)
{
    monsterType = value;
}

QList<MONSTER_SPECIAL> Monster::getMonsterSpecials() const
{
    return monsterSpecials;
}

void Monster::appendMonsterSpecials(MONSTER_SPECIAL ms)
{
    monsterSpecials.append(ms);
}

void Monster::deleteMonsterSpecials(MONSTER_SPECIAL ms)
{
    monsterSpecials.removeAll(ms);
}

int Monster::getOverwhelming() const
{
    return Overwhelming;
}

void Monster::setOverwhelming(int value)
{
    Overwhelming = value;
}

int Monster::getNightmarish() const
{
    return Nightmarish;
}

void Monster::setNightmarish(int value)
{
    Nightmarish = value;
}

int Monster::getHorror() const
{
    return Horror;
}

void Monster::setHorror(int value)
{
    Horror = value;
}

int Monster::getLoseSanity() const
{
    return loseSanity;
}

void Monster::setLoseSanity(int value)
{
    loseSanity = value;
}

int Monster::getCombat() const
{
    return Combat;
}

void Monster::setCombat(int value)
{
    Combat = value;
}

int Monster::getLoseStamina() const
{
    return loseStamina;
}

void Monster::setLoseStamina(int value)
{
    loseStamina = value;
}

int Monster::getAwareness() const
{
    return Awareness;
}

void Monster::setAwareness(int value)
{
    Awareness = value;
}

int Monster::getToughness() const
{
    return Toughness;
}

void Monster::setToughness(int value)
{
    Toughness = value;
}

OBJECT_TYPE Monster::getMonsterSymbol() const
{
    return monsterSymbol;
}


Monster::Monster(QString name, OBJECT_TYPE symbol):Token(name, TOKEN_MONSTER)
{
    monsterSymbol = symbol;
}


void MonsterBlack::MonsterMove(OBJECT_TYPE way)         //делают один шаг, если в локации с ними нет игроков
{
    Q_ASSERT( (way==MARK_BLACK) || (way == MARK_WHITE));
    Q_ASSERT (place != 0);
    if(!(static_cast<location*>(place)->containPlayer())){        //если игроков в текущей локации нет
        if(way == MARK_BLACK)
            moveToken(static_cast<location*>(place)->Black);
        else
            moveToken(static_cast<location*>(place)->White);
    }
}



void MonsterRed::MonsterMove(OBJECT_TYPE way)           //делают два шага, если по пути нет игроков
{
    Q_ASSERT( (way==MARK_BLACK) || (way == MARK_WHITE));
    location* target = static_cast<location*>(place);
    if(!target->containPlayer()){        //если игроков в текущей локации нет
        if(way == MARK_BLACK){
            moveToken(target->Black);
            if(!target->containPlayer()) moveToken(target->Black);
        }
        else {
            moveToken(target->White);
            if(!target->containPlayer()) moveToken(target->White);
        }
    }
}

investigator* getPlayerLessSneak(QList<investigator*> targets)
{
    if(!targets.isEmpty()){
        investigator* player = targets.first();
        if(targets.count() > 1) {                    //находим сыщика на улице с наименьшей скрытностью
            foreach (investigator* man, targets) {
                if(man->getSneak() > player->getSneak())
                    targets.removeAll(man);
                else if(man->getSneak() < player->getSneak()){
                    targets.removeAll(player);
                    player = man;
                }
            }
            foreach (investigator* man, targets) {
                if(man->getSneak() > player->getSneak())
                    targets.removeAll(man);
            }
        }
        if(targets.count() == 1) {
            return targets.first();
        }
        else {
            int pos = qrand()%targets.count();
            return *(targets.begin() + pos);
        }
    }
    return 0;
}


void MonsterBlue::MonsterMove(OBJECT_TYPE way)
{
    Q_ASSERT( (way==MARK_BLACK) || (way == MARK_WHITE) || (way == MARK_FLY));
    location* pl = static_cast<location*>(place);
    if(!pl->containPlayer()){
        investigator* player = 0;
        if(pl->getObjectType() == MAP_SKY){
            player = getPlayerLessSneak(Data::getData()->getPlayersOnStreets());
            if(player != 0)
                moveToken(player->place);
        }
        else {
            QList <investigator*> playerlist;
            foreach (location* nearPlace, pl->LstCommonPath) {
                playerlist.append(nearPlace->getPlayersOnLocation());
            }
            player = getPlayerLessSneak(playerlist);
            if(player != 0)
                moveToken(player->place);
            else
                moveToken(Data::getData()->sky);
        }
    }
}

void MonsterYellow::MonsterMove(OBJECT_TYPE way)
{
    return;//желтые монстры не двигаются - ничего не происходит
}

void MonsterPurple::MonsterMove(OBJECT_TYPE way)
{
    Q_ASSERT(way==MARK_BLACK || way == MARK_WHITE);
    location* pl = static_cast<location*>(place);
    if(!pl->containPlayer()){
        investigator* player = 0;
        QList <investigator*> playerlist;
        foreach (location* nearPlace, pl->LstCommonPath) {
            playerlist.append(nearPlace->getPlayersOnLocation());
        }
        player = getPlayerLessSneak(playerlist);
        if(player != 0)
            moveToken(player->place);
        else {
            //если игроков в текущей локации нет
            if(way == MARK_BLACK){
                moveToken(pl->Black);
            }
            else {
                moveToken(pl->White);
            }
        }
    }
}

void MonsterGreen::MonsterMove(OBJECT_TYPE way)
{
    useSpecialMove();
}

void MonsterOrange::MonsterMove(OBJECT_TYPE way)
{
    Q_ASSERT(way==MARK_BLACK || way == MARK_WHITE);
    location* pl = static_cast<location*>(place);
    if(!pl->containPlayer()){
        QList <investigator*> playerlist;
        foreach (location* loc, Data::getData()->locationList) {
            if(loc->containAquatic() && loc->containPlayer())
                playerlist.append(loc->getPlayersOnLocation());
        }
        investigator* player = getPlayerLessSneak(playerlist);
        if(player != 0) moveToken(player->place);
        else{
            if(way == MARK_BLACK) moveToken(pl->Black);
            else moveToken(pl->White);
        }
    }
}
//================================
//========= конструкторы =========

MonsterBlack::MonsterBlack(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_BLACK;
}

MonsterRed::MonsterRed(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    this->monsterType = MT_RED;
}

MonsterBlue::MonsterBlue(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_BLUE;
}

MonsterYellow::MonsterYellow(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_YELLOW;
}


MonsterPurple::MonsterPurple(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_PURPLE;
}


void MonsterGreen::SpecialMoveChthonian()
{
    //TODO бросок куба
    //4-6 каждый сыщик в аркхэме теряет 1 здоровье
}

MonsterGreen::MonsterGreen(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_GREEN;
}



MonsterOrange::MonsterOrange(QString name, OBJECT_TYPE symbol):Monster(name,symbol)
{
    monsterType = MT_ORANGE;
}

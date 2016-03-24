#ifndef MONSTERCOLLECTIONS
#define MONSTERCOLLECTIONS

#include "tokens/Monsters/monster.h"

//прототипы классов всех монстров


//черные



//Культист
class MonsterCultist:public MonsterBlack
{
public:
    MonsterCultist();
};

//Звездное отродье
class MonsterStarspawn:public MonsterBlack
{
public:
    MonsterStarspawn();
};

//Дитя козы
class MonsterChildOfTheGoat:public MonsterBlack
{
public:
    MonsterChildOfTheGoat();
};


class MonsterCrawlingOne:public MonsterBlack
{
public:
    MonsterCrawlingOne();
};




#endif // MONSTERCOLLECTIONS


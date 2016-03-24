#include "monstercollections.h"


MonsterCultist::MonsterCultist():MonsterBlack("Cultist",MARK_MOON)
{
    Nightmarish     = 0;
    Overwhelming    = 0;
    Horror          = 0;
    loseSanity      = 0;
    Combat          = 1;
    loseStamina     = 1;
    Awareness       = -3;
    Toughness       = 1;
}

MonsterStarspawn::MonsterStarspawn():MonsterBlack("Star Spawn",MARK_PLUS)
{
    Nightmarish     = 0;
    Overwhelming    = 0;
    Horror          = -3;
    loseSanity      = 2;
    Combat          = -3;
    loseStamina     = 3;
    Awareness       = -1;
    Toughness       = 3;
}



MonsterChildOfTheGoat::MonsterChildOfTheGoat():MonsterBlack("Child of the Goat",MARK_HEXAGON)
{
    Nightmarish     = 0;
    Overwhelming    = 0;
    Horror          = 0;
    loseSanity      = 0;
    Combat          = 1;
    loseStamina     = 0;
    Awareness       = -3;
    Toughness       = 1;

    //добавить абилку - при провале битвы или ухода сыщик задержан
}

MonsterCrawlingOne::MonsterCrawlingOne():MonsterBlack("Crawling One",MARK_CIRCLE)
{
    Nightmarish     = 0;
    Overwhelming    = 0;
    Horror          = -3;
    loseSanity      = 3;
    Combat          = 1;
    loseStamina     = 2;
    Awareness       = -1;
    Toughness       = 1;

    //добавить абилку - перед боем сила монстра равна числу выброшенному на кубе
}


#ifndef TYPES
#define TYPES

class Dummy{};

//TODO добавить потерян во времени и оба обморока


enum EVENT_TYPE{
    TT_NULL                 = 0,
    TT_GATE_BURST           = 1,      //прорыв врат
    TT_GATE_OPEN            = 2,       //открытие врат
    TT_GATE_CLOSE           = 3,      //закрытие врат
    TT_GATE_SEAL            = 4,       //запечатывание врат
    TT_MONSTER_APPEND       = 5,  //появляется монстр
    TT_MONSTER_SURGE        = 6,   //наплыв монстров
    TT_MONSTER_MOVE         = 7,    //движение монстра
    TT_MONSTER_OUTSKIRTS    = 8,   //монстр уходит на окраину
    TT_SYMBOL_MOVE          = 9,     //движение монстров одного символа
    TT_SYMBOL_REMOVE        = 10,   //уход монстров одного символа
    TT_LOST_OBJECT          = 11,     //удалить объект из инвентаря
    TT_GET_OBJECT           = 12,      //добавит объект в инвентарь
    TT_OBJECT_APPEND        = 13,   //добавить объект на поле из пула
    TT_OBJECT_REMOVE        = 14,    //убрать объект с поля в пул
    TT_OBJECT_DESTROY       = 15,   //убрать объект с поля в коробку
    TT_INCREASE_HORROR      = 16,
    TT_DECREASE_HORROR      = 17,
    TT_INCREASE_DOOM        = 18,
    TT_DECREASE_DOOM        = 19,
    TT_RESOLVE_CARD         = 20,    //розыгрыш карты (мифа, контакта)
    TT_DEVOURED             = 21,        //сыщик сожран
    TT_NEXT_PLAYER          = 22,     //передача жетона первого игрока
    TT_NEW_PROCESS          = 23,     //новый процесс
    TT_NEW_RUMORS           = 24,      //новый слух
    TT_ROLL                 = 25,             //бросок без проверки
    TT_ADD_OBJ_TO_CARD      = 26,  //положить объект на карту (миф, шмотка)
    TT_LOSE_OBJ_TO_CARD     = 27,     //снять объект с карты  (миф, шмотка)
    TT_OBJECT_MOVE          = 28,      //перемещение объекта по карте
    TT_NEXT_PHASE           = 29,       //начало фазы
    TT_SLAY_MONSTER         = 30,     //убийство монстра
    TT_START_ANCIENT_BATTLE = 31, //начало битвы с древним
    TT_SKILL_CHECK          = 32,         //проверка навыка
    TT_READING_SPELL        = 33,       //проверка заклинания
    TT_USE_SPECIAL          = 34,         //использование спецабилки
    TT_LOST_IN_TIME         = 35,        //сыщик потерян во времени и пространстве
    TT_INSANE               = 36,              //рассудок сыщика падает до 0
    TT_UNCONSCIOUS          = 37,         //здоровье сыщика падает до 0
    TT_ARRESTED             = 38,             //сыщик арестован
    TT_DELAYED              = 39,             //сыщик задержан
    TT_BLESSING             = 40,            //сыщик благословлен
    TT_CURSED               = 41,               //сыщик проклят
    TT_MOVING_START         = 42,        //начало перетаскивания сыщика игроком
    TT_MOVING_STOP          = 43,         //окончание перетаскивания сыщика игроком
    TT_TRADE                = 44,               //передача объектов другому сыщику
    TT_DISCARD_OBJECT       = 45,       //сбросить объект из инвентаря
    TT_GATE_CANCEL          = 46        //отмена открытия врат из-за печати или абилки


};

enum PHASE {
    UPKEEP,
    MOVEMENT,
    ENCOUNTER,
    OTHERWORLD,
    MITHOS
};

enum ABILITY {
    ABT_FIGHT,
    ABT_WILL,
    ABT_LORE,
    ABT_LUCK,
    ABT_SPEED,
    ABT_SNEAK,
    ABT_COMBAT,
    ABT_SPELL,
    ABT_EVADE,
    ABT_HORROR
};

enum ACTION {
    AT_WAIT = 0,    //ожидание хода
    AT_STOP = 1,    //
    AT_SLEEP,       //по окончанию хода
    AT_MOVE,
    AT_FIGHT,
    AT_ENCAUNTER,
    AT_CHECK,
    AT_CHANGE_STAT,
    AT_GET_CARD,
    AT_LOST_CARD
};

//токены можно брать себе
enum OBJECT_TYPE {
    OBJECT_UNKNOWN          = 0,

    TOKEN_CLUE              = 1,
    TOKEN_DOOM              = 2,
    TOKEN_ELDER_SIGN        = 3,
    TOKEN_GATE              = 4,
    TOKEN_BROOD             = 5,    //Жетон Эйхорта
    TOKEN_BAST              = 6,
    TOKEN_DUNWICH_HORROR    = 7,
    TOKEN_MONEY             = 8,
    TOKEN_POWER             = 9,
    TOKEN_RIFT              = 10,
    TOKEN_RUBBLE            = 11,  //Жетон Шуддль-Мьелла
    TOKEN_UPRISING          = 12,
    TOKEN_YELLOW_SIGN       = 13,
    TOKEN_ZHAR              = 14,
    TOKEN_FIRST_PLAYER      = 15,
    TOKEN_MONSTER           = 16,

    MARKER_ACTIVITY         = 17,           //активность
    MARKER_ANCIENT_WHISPER  = 18,    //древний шепот
    MARKER_AQUATIC          = 19,            //водная зона
    MARKER_CLOSE            = 20,              //закрыто
    MARKER_EXPLORED         = 21,           //исследовано
    MARKER_PATROL           = 22,             //патруль
    MARKER_INVESTIGATOR     = 23,       //сыщик
    MARKER_HORROR           = 24,
    MARKER_RUBBLE           = 25,         //Жетон Шуддль-Мьелла

    CARD_ENCAUNTER          = 26,
    CARD_OTHERWORLD         = 27,
    CARD_MYTHOS             = 28,
    CARD_EVENTS             = 29,            //карты обстоятельств - посмотреть перевод
    CARD_ITEM               = 30,
    CARD_ANCIENT            = 31,

    MAP_LOCATION            = 32,
    MAP_OUTSKIRTS           = 33,
    MAP_SKY                 = 34,

    MARK_MOON               = 35,            //символ мифа на монстре
    MARK_SQUARE             = 36,  //квадрат
    MARK_DIAMOND            = 37,   //ромб
    MARK_PLUS               = 38,    //плюс
    MARK_SLASH              = 39,
    MARK_CIRCLE             = 40,
    MARK_HEXAGON            = 41,
    MARK_TRIANGLE           = 42,
    MARK_STAR               = 43,

    MARK_BLACK              = 44,             //черная стрелка на карте
    MARK_WHITE              = 45,              //белая стрелка на карте
    MARK_FLY                = 46//для движения летающих монстров
};

enum MONSTER{
    MT_BLACK,
    MT_RED,
    MT_YELLOW,
    MT_PURPLE,
    MT_GREEN,
    MT_BLUE,
    MT_ORANGE
};

enum MONSTER_SPECIAL {
    MON_NIGHTMARISH,
    MON_OVERWHELMING,
    MON_AMBUSH,         //засада
    MON_ELUSIVE,        //скрытный
    MON_ENDLESS,        //неисчислимый
    MON_NAMELESS,       //безымянный
    MON_PHYSICAL_RESISTANCE,
    MON_MAGICAL_RESISTANCE,
    MON_WEAPON_RESISTANCE,
    MON_PHYSICAL_IMMUNITY,
    MON_MAGICAL_IMMUNITY,
    MON_WEAPON_IMMUNITY
};

enum CARD{
    CT_COMMON,
    CT_UNIQUE,
    CT_EXHIBIT,
    CT_SPELL,
    CT_SKILL,
    CT_ALLY,
    CT_SPECIAL,
    CT_INJURY,      //травмы
    CT_MADNESS      //безумия
};

enum ITEM_TYPE {
    NO_TYPE             = 0,
    PHYSICAL_WEAPON     = 1,
    MAGICAL_WEAPON      = 2,
    TOME                = 3,
    TASK                = 4
};

enum ITEM_SETTING {
    NO_SETTING          = 0,
    ITEM_HANDLESS       = 1,
    ITEM_ONE_HAND       = 2,
    ITEM_TWO_HAND       = 3,
    ITEM_CANNOT_BE_LOST = 4

};

enum EFFECT{        //Все бафы и дебафы, которые могут быть наложены на персонажа
    ET_BLESS            = 1,
    ET_CURSE            = 2,
    ET_FIGHT            = 3,
    ET_FIGHT_CHANGE     = 4, //изменение значения броска
    ET_SPEED            = 5,
    ET_SPEED_CHANGE     = 6,
    ET_SNEAK            = 7,
    ET_SNEAK_CHANGE     = 8,
    ET_WILL             = 9,
    ET_WILL_CHANGE      = 10,
    ET_LORE             = 11,
    ET_LORE_CHANGE      = 12,
    ET_LUCK             = 13,
    ET_LUCK_CHANGE      = 14,
    ET_COMBAT           = 15,
    ET_COMBAT_CHANGE    = 16,
    ET_SPELL            = 17,
    ET_SPELL_CHANGE     = 18,
    ET_HORROR           = 19,
    ET_HORROR_CHANGE    = 20,
    ET_EVADE            = 21,
    ET_EVADE_CHANGE     = 22,
    ET_SANITY,      //изменение пределов
    ET_STAMINA,
    ET_FOCUS
};

enum SETTING{       //опции, включенные в игру
    ST_LIAGUE,
    ST_RELATIONSHIP,
    ST_EPIC_BATTLE,
    ST_PERSONAL_STORY,
    ST_INJURY,      //травмы и безумия
    ST_DUNWICH_MAP,     //использование игровых полей
    ST_KINGSPORT_MAP,
    ST_INNSMOUTH_MAP,
    ST_CORRUPTIONS,
    ST_VISITING_EXHIBIT,
    ST_PERMANENT_EXHIBIT,
    ST_ACT,
    ST_BLIGHT,
    ST_TOURING_PERFORMANCE,
    ST_PERMANENT_PERFORMANCE,
    ST_GUARDIAN,
    ST_HERALD,
    ST_DIFFICULTY,

    ST_DH_COMMON,
    ST_KH_COMMON,
    ST_BGW_COMMON,
    ST_KY_COMMON,
    ST_LT_COMMON,
    ST_DH_SKILL,
    ST_KH_SKILL,
    ST_DF_SPELL,    //заклинания из темного фараона
    ST_DH_SPELL,
    ST_KH_SPELL,
    ST_BGW_SPELL,
    ST_KY_SPELL,
    ST_LT_SPELL,
    ST_DH_UNIQUE,
    ST_KH_UNIQUE,
    ST_BGW_UNIQUE,
    ST_KY_UNIQUE,
    ST_LT_UNIQUE,
    ST_DF_ALLY,     //союзники из темного фараона
    ST_DH_ALLY,
    ST_KH_ALLY,
    ST_EXHIBIT

};
#endif // TYPES

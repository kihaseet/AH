#ifndef DATA_H
#define DATA_H
#include <QMap>
#include "tokens/Cards/commonitemscollection.h"
#include "tokens/gate.h"
#include "tokens/Monsters/monstercollections.h"
#include "triggers/mythos.h"
#include "investigator/player.h"
#include "map/location.h"

class Mythos;
class Trigger;


// класс данных, хранит в себе списки всех игровых объектов и методы доступа к ним
// объект, единожды созданный, во время игры переходит из одного списка в другой
// реализован через синглтон, чтобы в единый момент времени существовал только один экземпляр класса

class Data
{
private:
    QMap<int,Monster*> globalMonsterList;           // здесь постоянно хранятся все объекты монстров
    QMap<int,Gate*> globalGateList;                 // все объекты врат
    QMap<int,Mythos*> globalMythosDeck;             // все объекты карт Мифа

    QList<Card*> deckCommonItems;                   // колода простых вещей
    QList<Card*> deckUniqueItems;                   // колода уникальных вещей


    investigator* currPlayer;                       // указатель на текущего игрока (совершающего действие)
    int round;                                      // номер хода
    PHASE currPhase;                                // текущая игровая фаза

    QList<Token*> HorrorTrack;                      // список трека ужаса
    QList<Token*> DoomTrack;                        // список трека безысходности

    QList<Token*> cupDoomToken;                     // пул жетонов безысходности и печатей
    QList<Token*> cupClueToken;                     // пул улик
    QList<Token*> cupPowerToken;                    // пул жетонов Силы

    IObject* currProcessCard;                       // указатель на текущий процесс


    static Data* m_instData;                        // указатель на единственный эклемпляр класса
    static void DestroyData();
protected:
    Data();
public:
    QMap<investigator *, ACTION> playerlist;        // список игроков и их статусы
    int limitMonster;                               // предел мостров в аркхэме
    int countMonster;                               // количество монстров в аркхэме
    int limitGates;                                 // предел врат в аркхэме
    int countGates;                                 // количество врат в аркхэме
    int limitOutskirts;                             // предел окраин
    int countOutskirts;                             // количество монстров на окраинах
    int currentHorror;                              // текущий уровень ужаса

    location* outskirts;                            // указатель на локацию Окраины
    location* sky;                                  // указатель на локацию Небо
    QList<location*> locationList;                  // список всех локаций
    QList<Gate*> gatePool;                          // пул жетонов врат
    QList<Trigger*> triggerPool;                    // пул триггеров
    QList<Monster*> monsterPool;                    // пул монстров
    QList<Mythos*> MythosDeck;                      // колода Мифов
    static Data* getData();                         // статический метод, через который мы обращается к данным

    Gate* getRandomFreeGate();                      // возвращает случайный указатель на жетон врат в пуле врат, удаляя его из пула
    Monster* getRandemFreeMonster();                // возвращает случайный указатель на жетон монстра в пуле врат, удаляя его из пула
    Mythos* getUpperMythos();                       // возвращает указатель на верхнюю карту Мифа в колоде, удаляя ее из колоды
    Card* getUpperCommonItem();                     // возвращает указатель на верхнюю карту простой вещи в колоде, удаляя ее из пула

    void returnObjectToDeck(IObject *object);       // возвращает объект в его родной пул

    void insertGlobalMonsterList(Monster* monster); //
    void removeGlobalMonsterList(Monster* monster);
    void insertGlobalGateList(Gate* gate);
    void removeGlobalGateList(Gate* gate);
    void insertGlobalMythosDeck(Mythos* mythos);
    void removeGlobalMythosDeck(Mythos *mythos);



    void InitializeGameData();                      //начальная инициализация данных
    void appendTokenDoomTrack(Token* token);
    void removeLastTokenDoomTrack();
    Token* getDoomFromCup();
    void setDoomToCup(Token* token);
    location* getLocationByName(QString name);
    location* findLocationContain(Token *object); //найти локацию, содержащую объект
    QList<investigator*> getPlayersOnStreets();
    Token *getElderSignFromCup();
    void setElderSignToCup(Token *token);
};

#endif // DATA_H

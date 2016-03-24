#ifndef LOCATION_H
#define LOCATION_H
#include <QObject>
#include "investigator/player.h"
#include "tokens/iobject.h"
#include "tokens/token.h"
#include "tokens/Monsters/monster.h"
#include "tokens/gate.h"

class Token;
class Gate;
class Monster;

class location: public IObject
{
    int id;
    int idDistrict;                     //номер района
    bool isStable;                      //true - зеленый ромб, false - красный
    bool isStreet;                      //true - улица, false - локация
public:
    location(QString name, int idDistrict, bool isStable, bool isStreet);

    location* Black;                    //указатель на смежную локацию по белой стрелке
    location* White;                    //указатель на смежную локацию по черной стрелке
    QList <location*> LstCommonPath;    //список смежных локаций для сыщиков
    QList <Monster*> getMonsters();     //возвращает список всех находящихся в локации монстров
    Gate* getGate();                    //возвращает указатель на жетон врат, открытых в локации, или 0, если там их нет
    bool containPlayer();               //true если содержит хотя бы одного игрока, false
    bool containAquatic();              //true содержит жетон водной локации, false - нет
    Token* getSeal();
    QList <investigator*> getPlayersOnLocation();
    bool getIsStreet() const;
    void setIsStreet(bool value);
};



/*
 * список районов по idDistrict:
 * 1 - Downtown (for Arkham Asylum, Bank of Arkham, Independence Square)
 * 2 - Easttown (for Hibb's Roadhouse, Police Station, Velma's Diner)
 * 3 - French Hill (for Silver Twilight Lodge, Witch House)
 * 4 - Merchant District (for River Docks, the Unnameable, Unvisited Isle)
 * 5 - Miscatonic Universiry (for Administration, Library, Science Building)
 * 6 - Northside (for Curiositie Shoppe, Newspaper, Train Station)
 * 7 - Rivertown (for Black Cave, General Store, Graveyard)
 * 8 - Southside (for Historical Society, Ma's Boarding House, South Church)
 * 9 - Uptown (for Saint Mary's Hospital, Ye Olde Magick Shoppe, Woods)
 * =============== Dunwich ========================
 * 10 - Blackwoods Country (for Cold Spring Glen, Whateley Farm, Wizard's Hill)
 * 11 - Blasted Heath (for Devil's Hopyard, Gardners' Place, Harney Jones Shack)
 * 12 - Village Commons (for Bishop's Brook Bridge, Darke's Carnival, Dunwich Village)
 * ============== Kingsport =======================
 * 13 - Central Hill (for 7th House on the Left, Congregational Hospital, St Erasmus's Home)
 * 14 - Harborside (for 607 Water St., North Point Lighthouse, the Rope and Anchor)
 * 15 - Kingsport Head (for the Causeway, Str. High House in the Mist, Wireless Station)
 * 16 - South Shore (for Artists' Colony, the Hall School, Neil's Curiosity Shop)
 * ============== Innsmouth =======================
 * 17 - Church Green (for Esoteric Order of Dagon, Innsmouth Jail, Sawbone Alley)
 * 18 - Factory District (for First National Grocery, Gilman House Hotel, March Refinery)
 * 19 - Innsmouth Shore (for Devil Reef, Falcon Point, Y'ha-Nthlei)
 *
 */

#endif // LOCATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "data.h"
#include "triggers/eventobject.h"
#include "triggers/eventcollections.h"
#include "tokens/Cards/commonitemscollection.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Data::getData()->InitializeGameData();

    investigator* io = new investigator("Darrel");

    EventObject::createEvent(TT_GET_OBJECT,io,Data::getData()->getUpperCommonItem())->runEvent();
    //

    EventObject::createEvent(TT_RESOLVE_CARD,Data::getData()->getUpperMythos(),CARD_MYTHOS)->runEvent();
    EventObject::createEvent(TT_GATE_CLOSE,0,Data::getData()->getLocationByName("Woods")->getGate())->runEvent();
    EventObject::createEvent(TT_GATE_SEAL,Data::getData()->getLocationByName("Woods"),0)->runEvent();
    EventObject::createEvent(TT_GATE_OPEN,Data::getData()->getRandomFreeGate(),Data::getData()->getLocationByName("Woods"))->runEvent();

    foreach (location* loc, Data::getData()->locationList) {
        foreach (IObject* token, loc->tokenPool) {
            qDebug()<<loc->name<<token->name<<token->getIObjectID();
        }
    }

    return app.exec();
}


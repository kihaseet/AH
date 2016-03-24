TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    investigator/player.cpp \
    map/location.cpp \
    tokens/token.cpp \
    triggers/abstractcondition.cpp \
    triggers/trigger.cpp \
    data.cpp \
    triggers/eventobject.cpp \
    tokens/iobject.cpp \
    game.cpp \
    triggers/eventcollections.cpp \
    tokens/gate.cpp \
    triggers/triggercollections.cpp \
    triggers/mythos.cpp \
    tokens/Monsters/monster.cpp \
    tokens/Monsters/monsterblack.cpp \
    tokens/Cards/card.cpp \
    tokens/Cards/commonitemscollection.cpp \
    tokens/Cards/itemaction.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    investigator/player.h \
    map/location.h \
    tokens/token.h \
    triggers/abstractcondition.h \
    triggers/trigger.h \
    data.h \
    types.h \
    triggers/eventobject.h \
    tokens/iobject.h \
    game.h \
    triggers/eventcollections.h \
    tokens/gate.h \
    triggers/triggercollections.h \
    triggers/mythos.h \
    tokens/Monsters/monster.h \
    tokens/Monsters/monstercollections.h \
    tokens/Cards/card.h \
    tokens/Cards/commonitemscollection.h \
    tokens/Cards/itemaction.h


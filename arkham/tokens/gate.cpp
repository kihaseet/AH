#include "gate.h"


OBJECT_TYPE Gate::getMythosSymbol() const
{
    return MythosSymbol;
}

void Gate::setMythosSymbol(const OBJECT_TYPE &value)
{
    MythosSymbol = value;
}

Gate::Gate(QString name):Token(name, TOKEN_GATE)
{
}


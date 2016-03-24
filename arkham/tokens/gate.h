#ifndef GATE_H
#define GATE_H
#include <QString>
#include "tokens/token.h"
#include "types.h"

class Gate: public Token
{
protected:
    OBJECT_TYPE MythosSymbol;
public:
    Gate(QString name);
    OBJECT_TYPE getMythosSymbol() const;
    void setMythosSymbol(const OBJECT_TYPE &value);
};

#endif // GATE_H

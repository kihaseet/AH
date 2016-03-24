#ifndef TOKEN_H
#define TOKEN_H
#include "tokens/iobject.h"


class Token:public IObject
{
public:

    Token(QString name, OBJECT_TYPE type);
    void moveToken(IObject *to);       //переместить жетон по полю
    void placeToken(IObject* to);      //поместить жетон на поле
    void removeToken();    //снять жетон с поля
};

#endif // TOKEN_H

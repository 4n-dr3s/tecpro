// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionPush.h"

InstruccionPush::InstruccionPush(int _c)
{
    c = _c;
}

void InstruccionPush::ejecutar(stack<int> *s)
{
    s->push(c);
}

void InstruccionPush::listar()
{
    cout << "push " << c << endl;
}
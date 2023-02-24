// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionJumpif.h"

InstruccionJumpif::InstruccionJumpif(int _l)
{
    l = _l;
}

void InstruccionJumpif::ejecutar(stack<int> *s) {}

void InstruccionJumpif::ejecutar(stack<int> *s, int &counter)
{
    int x = s->top();
    s->pop();
    if (x >= 0)
    {
        counter = l;
    }
    else
    {
        counter++;
    }
}

void InstruccionJumpif::listar()
{
    cout << "jumpif " << l << endl;
}
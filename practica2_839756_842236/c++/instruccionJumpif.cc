// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionJumpif.h"

InstruccionJumpif::InstruccionJumpif(int _l)
{
    l = _l;
}

void InstruccionJumpif::ejecutar(stack<int> *s /*, int &counter*/)
{
    int x = s->top();
    s->pop();
    if (x >= 0)
    {
        // counter = l;
    }
}

void InstruccionJumpif::listar()
{
    cout << "jumpif " << l << endl;
}

bool InstruccionJumpif::esJumpif()
{
    return true;
}
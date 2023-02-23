// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionJumpif.h"

InstruccionJumpif::InstruccionJumpif(int _l)
{
    l = _l;
}

void InstruccionJumpif::ejecutar(stack<int> *s)
{
    int x = s->top();
    s->pop();
    if (x >= 0)
    {
        // Saltar a la línea l
    }
}

void InstruccionJumpif::listar()
{
    cout << "jumpif " << l << endl;
}
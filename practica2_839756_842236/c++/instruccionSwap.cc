// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionSwap.h"

void InstruccionSwap::ejecutar(stack<int> *s)
{
    int x, y;
    x = s->top();
    s->pop();
    y = s->top();
    s->pop();
    s->push(x);
    s->push(y);
}

void InstruccionSwap::listar()
{
    cout << "swap" << endl;
}
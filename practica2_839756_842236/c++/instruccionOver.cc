// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionOver.h"

void InstruccionOver::ejecutar(stack<int> *s)
{
    int x, y;
    x = s->top();
    s->pop();
    y = s->top();
    s->pop();
    s->push(y);
    s->push(x);
    s->push(y);
}

void InstruccionOver::listar()
{
    cout << "over" << endl;
}
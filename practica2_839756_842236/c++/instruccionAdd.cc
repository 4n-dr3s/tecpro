// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionAdd.h"

void InstruccionAdd::ejecutar(stack<int> *s)
{
    int x, y, res;
    x = s->top();
    s->pop();
    y = s->top();
    s->pop();
    res = x + y;
    s->push(res);
}

void InstruccionAdd::listar()
{
    cout << "add" << endl;
}
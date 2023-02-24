// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionMul.h"

void InstruccionMul::ejecutar(stack<int> *s)
{
    int x, y;
    x = s->top();
    s->pop();
    y = s->top();
    s->pop();
    s->push(y * x);
}

void InstruccionMul::listar()
{
    cout << "mul" << endl;
}
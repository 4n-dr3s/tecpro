// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionWrite.h"

void InstruccionWrite::ejecutar(stack<int> *s)
{
    int x;
    x = s->top();
    s->pop();
    cout << x << endl;
}

void InstruccionWrite::listar()
{
    cout << "write" << endl;
}
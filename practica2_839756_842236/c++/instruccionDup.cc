// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionDup.h"

void InstruccionDup::ejecutar(stack<int> *s)
{
    int x;
    x = s->top();
    s->push(x);
}

void InstruccionDup::listar()
{
    cout << "dup" << endl;
}
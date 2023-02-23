// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccionRead.h"

void InstruccionRead::ejecutar(stack<int> *s)
{
    int x;
    cout << "? ";
    cin >> x;
    s->push(x);
}

void InstruccionRead::listar()
{
    cout << "read" << endl;
}
// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaSuma.h"

ProgramaSuma::ProgramaSuma()
{
    instrucciones[0] = new InstruccionRead();
    instrucciones[1] = new InstruccionRead();
    instrucciones[2] = new InstruccionAdd();
    instrucciones[3] = new InstruccionWrite();
}

void ProgramaSuma::ejecutar()
{
    stack<int> *s = new stack<int>;
    cout << "Ejecución:" << endl;
    for (int i = 0; i < len; i++)
    {
        instrucciones[i]->ejecutar(s);
    }
}

void ProgramaSuma::listar()
{
    cout << "Programa:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << i << "  ";
        instrucciones[i]->listar();
    }
}
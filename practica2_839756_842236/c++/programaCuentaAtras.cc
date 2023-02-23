// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaCuentaAtras.h"

ProgramaCuentaAtras::ProgramaCuentaAtras()
{
    instrucciones[0] = new InstruccionRead();
    instrucciones[1] = new InstruccionDup();
    instrucciones[2] = new InstruccionWrite();
    instrucciones[3] = new InstruccionPush(-1);
    instrucciones[4] = new InstruccionAdd();
    instrucciones[5] = new InstruccionDup();
    instrucciones[6] = new InstruccionJumpif(1);
}

void ProgramaCuentaAtras::ejecutar()
{
    stack<int> *s = new stack<int>;
    int counter = 0;
    cout << "Ejecución:" << endl;
    while (counter < len)
    {
        instrucciones[counter]->ejecutar(s);
        counter++;
    }
}

void ProgramaCuentaAtras::listar()
{
    cout << "Programa:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << i << "  ";
        instrucciones[i]->listar();
    }
}
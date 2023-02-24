// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "instruccion.h"

void Instruccion::ejecutar(stack<int> *s, int &counter)
{
    ejecutar(s);
    counter++;
}
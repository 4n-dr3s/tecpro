// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "instruccion.h"

class InstruccionPush : public Instruccion
{
private:
    int c;

public:
    InstruccionPush(int _c);
    void ejecutar(stack<int> *s);
    void listar();
};
// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "instruccion.h"

class InstruccionPush : public Instruccion
{
private:
    int c;

public:
    InstruccionPush(int _c);
    // Redefine la forma de ejecutar
    void ejecutar(stack<int> *s);
    // Redefine la forma de listar
    void listar();
};
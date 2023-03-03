// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "instruccion.h"

class InstruccionJumpif : public Instruccion
{
private:
    int l;

public:
    InstruccionJumpif(int _l);
    // Redefine la forma de ejecutar
    void ejecutar(stack<int> *s);
    // Redefine la forma de ejecutar
    void ejecutar(stack<int> *s, int &counter);
    // Redefine la forma de listar
    void listar();
};
// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "instruccion.h"

class InstruccionRead : public Instruccion
{
public:
    // Redefine la forma de ejecutar
    void ejecutar(stack<int> *s);
    // Redefine la forma de listar
    void listar();
};
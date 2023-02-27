// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include <iostream>
#include <stack>
#include "instruccion.h"

using namespace std;
using InstruccionPtr = Instruccion *;

class Programa
{
public:
    virtual void ejecutar() = 0;
    virtual void listar() = 0;
};
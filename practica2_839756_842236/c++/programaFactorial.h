// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"

class ProgramaFactorial
{
private:
    const int len = 14;
    InstruccionPtr *instrucciones = new InstruccionPtr[len];

public:
    ProgramaFactorial();
    void ejecutar();
    void listar();
};

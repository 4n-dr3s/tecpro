// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"

class ProgramaCuentaAtras
{
private:
    const int len = 7;
    InstruccionPtr *instrucciones = new InstruccionPtr[len];

public:
    ProgramaCuentaAtras();
    void ejecutar();
    void listar();
};
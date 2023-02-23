// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"
#include "instruccionRead.h"
#include "instruccionAdd.h"
#include "instruccionWrite.h"

class ProgramaSuma
{
private:
    const int len = 4;
    InstruccionPtr *instrucciones = new InstruccionPtr[len];

public:
    ProgramaSuma();
    void ejecutar();
    void listar();
};
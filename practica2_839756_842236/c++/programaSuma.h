// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"
#include "instruccionRead.h"
#include "instruccionAdd.h"
#include "instruccionWrite.h"

class ProgramaSuma
{
protected:
    const int len = 4;
    InstruccionPtr *instrucciones = new InstruccionPtr[len];
    stack<int> *s;

public:
    ProgramaSuma();
    virtual void ejecutar();
    virtual void listar();
};
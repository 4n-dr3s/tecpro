// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"
#include "instruccionRead.h"
#include "instruccionAdd.h"
#include "instruccionWrite.h"
#include "instruccionPush.h"
#include "instruccionDup.h"
#include "instruccionJumpif.h"

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
// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "programa.h"
#include "instruccionRead.h"
#include "instruccionAdd.h"
#include "instruccionWrite.h"
#include "instruccionPush.h"
#include "instruccionDup.h"
#include "instruccionJumpif.h"
#include "instruccionMul.h"
#include "instruccionSwap.h"
#include "instruccionOver.h"

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

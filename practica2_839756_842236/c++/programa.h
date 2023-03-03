// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include "instruccion.h"
#include "instruccionRead.h"
#include "instruccionAdd.h"
#include "instruccionWrite.h"
#include "instruccionPush.h"
#include "instruccionDup.h"
#include "instruccionJumpif.h"
#include "instruccionMul.h"
#include "instruccionSwap.h"
#include "instruccionOver.h"

using namespace std;
using InstruccionPtr = Instruccion *;

class Programa
{
public:
    virtual void ejecutar() = 0;
    virtual void listar() = 0;
};
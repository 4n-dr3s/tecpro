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
protected:
    int len = 0;                   // Número de instrucciones a ejecutar
    InstruccionPtr *instrucciones; // Puntero a puntero de instrucciones

public:
    void ejecutar();
    void listar();
};
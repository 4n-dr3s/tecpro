// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaFactorial.h"

ProgramaFactorial::ProgramaFactorial()
{
    len = 14;                                // Número de instrucciones a ejecutar
    instrucciones = new InstruccionPtr[len]; // Reservamos espacio para "len" instrucciones

    // Instrucciones del programa
    instrucciones[0] = new InstruccionPush(1);
    instrucciones[1] = new InstruccionRead();
    instrucciones[2] = new InstruccionSwap();
    instrucciones[3] = new InstruccionOver();
    instrucciones[4] = new InstruccionMul();
    instrucciones[5] = new InstruccionSwap();
    instrucciones[6] = new InstruccionPush(-1);
    instrucciones[7] = new InstruccionAdd();
    instrucciones[8] = new InstruccionDup();
    instrucciones[9] = new InstruccionPush(-2);
    instrucciones[10] = new InstruccionAdd();
    instrucciones[11] = new InstruccionJumpif(2);
    instrucciones[12] = new InstruccionSwap();
    instrucciones[13] = new InstruccionWrite();
};
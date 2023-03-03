// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaCuentaAtras.h"

ProgramaCuentaAtras::ProgramaCuentaAtras()
{
    len = 7;                                 // Número de instrucciones a ejecutar
    instrucciones = new InstruccionPtr[len]; // Reservamos espacio para "len" instrucciones

    // Instrucciones del programa
    instrucciones[0] = new InstruccionRead();
    instrucciones[1] = new InstruccionDup();
    instrucciones[2] = new InstruccionWrite();
    instrucciones[3] = new InstruccionPush(-1);
    instrucciones[4] = new InstruccionAdd();
    instrucciones[5] = new InstruccionDup();
    instrucciones[6] = new InstruccionJumpif(1);
};
// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaSuma.h"

ProgramaSuma::ProgramaSuma()
{
    len = 4;                                 // Número de instrucciones a ejecutar
    instrucciones = new InstruccionPtr[len]; // Reservamos espacio para "len" instrucciones

    // Instrucciones del programa
    instrucciones[0] = new InstruccionRead();
    instrucciones[1] = new InstruccionRead();
    instrucciones[2] = new InstruccionAdd();
    instrucciones[3] = new InstruccionWrite();
}
public class ProgramaCuentaAtras extends Programa {
    public ProgramaCuentaAtras() {
        len = 7; // Número de instrucciones
        instrucciones = new Instruccion[len];

        // Instrucciones del programa
        instrucciones[0] = new InstruccionRead();
        instrucciones[1] = new InstruccionDup();
        instrucciones[2] = new InstruccionWrite();
        instrucciones[3] = new InstruccionPush(-1);
        instrucciones[4] = new InstruccionAdd();
        instrucciones[5] = new InstruccionDup();
        instrucciones[6] = new InstruccionJumpif(1);
    }

}

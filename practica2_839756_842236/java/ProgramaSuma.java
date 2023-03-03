public class ProgramaSuma extends Programa {
    public ProgramaSuma() {
        len = 4; // Número de instrucciones
        instrucciones = new Instruccion[len];

        // Instrucciones del programa
        instrucciones[0] = new InstruccionRead();
        instrucciones[1] = new InstruccionRead();
        instrucciones[2] = new InstruccionAdd();
        instrucciones[3] = new InstruccionWrite();
    }
}

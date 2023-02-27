import java.util.Stack;

public class ProgramaCuentaAtras extends Programa {
    private int len = 7;
    private Instruccion[] instrucciones = new Instruccion[len];

    public ProgramaCuentaAtras() {
        instrucciones[0] = new InstruccionRead();
        instrucciones[1] = new InstruccionDup();
        instrucciones[2] = new InstruccionWrite();
        instrucciones[3] = new InstruccionPush(-1);
        instrucciones[4] = new InstruccionAdd();
        instrucciones[5] = new InstruccionDup();
        instrucciones[6] = new InstruccionJumpif(1);
    }

    public void ejecutar() {
        Stack<Integer> s = new Stack<Integer>();
        System.out.println("Ejecución:");
        int counter = 0;
        while (counter >= 0 && counter < len) {
            instrucciones[counter].ejecutar(s, counter);
        }
    }

    public void listar() {
        System.out.println("Programa:");
        for (int i = 0; i < len; i++) {
            System.out.print(i + " ");
            instrucciones[i].listar();
        }
    }
}

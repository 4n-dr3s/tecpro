import java.util.Stack;
import java.util.concurrent.atomic.AtomicInteger;

public class ProgramaFactorial extends Programa {
    private int len = 14;
    private Instruccion[] instrucciones = new Instruccion[len];

    public ProgramaFactorial() {
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
    }

    public void ejecutar() {
        Stack<Integer> s = new Stack<Integer>();
        System.out.println("Ejecución:");
        AtomicInteger counter = new AtomicInteger(0);
        while (counter.get() >= 0 && counter.get() < len) {
            instrucciones[counter.get()].ejecutar(s, counter);
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

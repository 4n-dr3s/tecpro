import java.util.Stack;
import java.util.concurrent.atomic.AtomicInteger;

public class ProgramaSuma extends Instruccion {

    private int len = 4;
    private Instruccion[] instrucciones = new Instruccion[len];

    public ProgramaSuma() {
        instrucciones[0] = new InstruccionRead();
        instrucciones[1] = new InstruccionRead();
        instrucciones[2] = new InstruccionAdd();
        instrucciones[3] = new InstruccionWrite();
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

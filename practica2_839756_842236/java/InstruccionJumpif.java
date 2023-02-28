import java.util.Stack;
import java.util.concurrent.atomic.AtomicInteger;

public class InstruccionJumpif extends Instruccion {
    private int l;

    public InstruccionJumpif(int _l) {
        l = _l;
    }

    @Override
    public void ejecutar(Stack<Integer> s) {
    }

    @Override
    public void ejecutar(Stack<Integer> s, AtomicInteger counter) {
        int x = s.pop();
        if (x >= 0) {
            counter.set(l);
        } else {
            counter.getAndIncrement();
        }
    }

    public void listar() {
        System.out.println("jumpif " + l);
    }
}

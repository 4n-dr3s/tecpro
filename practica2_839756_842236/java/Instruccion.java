import java.util.Stack;
import java.util.concurrent.atomic.AtomicInteger;

public class Instruccion {
    public void ejecutar(Stack<Integer> s) {
    }

    public void ejecutar(Stack<Integer> s, AtomicInteger counter) {
        ejecutar(s);
        counter.getAndIncrement();
    }

    public void listar() {
    }
}
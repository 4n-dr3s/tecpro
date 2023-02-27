import java.util.Stack;

public class Instruccion {
    public void ejecutar(Stack<Integer> s) {
    }

    public void ejecutar(Stack<Integer> s, int counter) {
        ejecutar(s);
        counter++;
    }

    public void listar() {
    }
}
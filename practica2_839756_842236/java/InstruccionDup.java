import java.util.Stack;

public class InstruccionDup extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        int x = s.peek();
        s.push(x);
    }

    @Override
    public void listar() {
        System.out.println("dup");
    }
}

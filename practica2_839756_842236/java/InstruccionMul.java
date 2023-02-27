import java.util.Stack;

public class InstruccionMul extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        int x = s.pop();
        int y = s.pop();
        s.push(y * x);
    }

    @Override
    public void listar() {
        System.out.println("mul");
    }
}

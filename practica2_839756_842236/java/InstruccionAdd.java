import java.util.Stack;

public class InstruccionAdd extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        int x = s.pop();
        int y = s.pop();
        s.push(x + y);
    }

    @Override
    public void listar() {
        System.out.println("add");
    }
}

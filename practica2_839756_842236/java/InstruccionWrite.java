import java.util.Stack;

public class InstruccionWrite extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        int x = s.pop();
        System.out.println(x);
    }

    @Override
    public void listar() {
        System.out.println("write");
    }
}

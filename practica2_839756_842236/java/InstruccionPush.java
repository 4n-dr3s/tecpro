import java.util.Stack;

public class InstruccionPush extends Instruccion {
    private int c;

    InstruccionPush(int _c) {
        c = _c;
    }

    @Override
    public void ejecutar(Stack<Integer> s) {
        s.push(c);
    }

    @Override
    public void listar() {
        System.out.println("push " + c);
    }
}

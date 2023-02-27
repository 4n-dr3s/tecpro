import java.util.Stack;

public class InstruccionJumpif extends Instruccion {
    private int l;

    public InstruccionJumpif(int _l) {
        l = _l;
    }

    @Override
    public void ejecutar(Stack<Integer> s) {
    }

    @Override
    public void ejecutar(Stack<Integer> s, int counter) {
        int x = s.pop();
        if (x >= 0) {
            counter = l;
        } else {
            counter++;
        }
    }

    public void listar() {
        System.out.println("jumpif " + l);
    }
}

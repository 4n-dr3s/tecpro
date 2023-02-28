import java.util.Scanner;
import java.util.Stack;

public class InstruccionRead extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        System.out.print("? ");
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        s.push(x);
    }

    @Override
    public void listar() {
        System.out.println("read");
    }
}

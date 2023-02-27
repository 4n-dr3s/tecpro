import java.util.Stack;

public class ProgramaSuma extends Instruccion {

    private int len = 4;
    private Instruccion[] instrucciones = new Instruccion[len];

    public ProgramaSuma() {
        instrucciones[0] = new InstruccionRead();
        instrucciones[1] = new InstruccionRead();
        instrucciones[2] = new InstruccionAdd();
        instrucciones[3] = new InstruccionWrite();
    }

    public void ejecutar() {
        Stack<Integer> s = new Stack<Integer>();
        System.out.println("Ejecución:");
        int counter = 0;
        while (counter >= 0 && counter < len) {
            instrucciones[counter].ejecutar(s);
        }
    }

    public void listar() {
        System.out.println("Programa:");
        for (int i = 0; i < len; i++) {
            System.out.print(i + " ");
            instrucciones[i].listar();
        }
    }
}

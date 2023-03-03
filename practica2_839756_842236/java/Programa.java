import java.util.Stack;
import java.util.concurrent.atomic.AtomicInteger;

public class Programa {
    protected int len = 0;
    protected Instruccion[] instrucciones;

    public void ejecutar() {
        // Creamos la pila
        Stack<Integer> s = new Stack<Integer>();
        System.out.println("Ejecución:");
        // Creamos una variable para el contador de programa
        AtomicInteger counter = new AtomicInteger(0);
        // Iteramos por cada una de las instrucciones del programa
        while (counter.get() >= 0 && counter.get() < len) {
            // Ejecutamos la instrucción
            instrucciones[counter.get()].ejecutar(s, counter);
        }
    }

    public void listar() {
        System.out.println("Programa:");
        // Iteramos por cada una de las instrucciones
        for (int i = 0; i < len; i++) {
            // Listamos la instrucción
            System.out.print(i + " ");
            instrucciones[i].listar();
        }
    }
}

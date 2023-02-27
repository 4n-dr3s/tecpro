import java.util.Scanner;
import java.util.Stack;

public class InstruccionRead extends Instruccion {
    @Override
    public void ejecutar(Stack<Integer> s) {
        /*
         * String name = new String();
         * int age;
         * 
         * Scanner scanner = new Scanner(System.in);
         * 
         * System.out.print("Holaaa!! Cómo te llamas? ");
         * System.out.flush();
         * name = scanner.next();
         * System.out.print("What's your age ? ");
         * System.out.flush();
         * age = scanner.nextInt();
         * System.out.println("Hello, " + name + " !!");
         * System.out.println("You're " + age + " years old");
         */

        System.out.print("? ");
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        System.out.flush();
        s.push(x);
        System.out.print("? ");
        x = in.nextInt();
        System.out.flush();
        s.push(x);
    }

    @Override
    public void listar() {
        System.out.println("read");
    }
}

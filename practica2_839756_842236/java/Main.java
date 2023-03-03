public class Main {
    public static void main(String[] args) {
        // Simulamos programa suma
        ProgramaSuma programa0 = new ProgramaSuma();
        programa0.listar();
        System.out.println("");
        programa0.ejecutar();
        System.out.println("");

        // Simulamos programa cuenta atrás
        ProgramaCuentaAtras programa1 = new ProgramaCuentaAtras();
        programa1.listar();
        System.out.println("");
        programa1.ejecutar();
        System.out.println("");

        // Simulamos programa factorial
        ProgramaFactorial programa2 = new ProgramaFactorial();
        programa2.listar();
        System.out.println("");
        programa2.ejecutar();
    }
}
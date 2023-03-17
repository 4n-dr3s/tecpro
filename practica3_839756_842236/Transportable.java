// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

// La clase Transportable representa objetos que pueden ser cargados en un objeto de tipo Contenedor
abstract class Transportable implements Guardable {

    protected String nombre;
    protected double volumen;
    protected double peso;

    public String nombre() {
        // Devuelve el nombre
        return nombre;
    }

    public double volumen() {
        // Devuelve el volumen
        return volumen;
    }

    public double peso() {
        // Devuelve el peso
        return peso;
    }

    public String mostrar(int nivel) {
        // Muestra por pantalla el nombre, volumen y peso de la clase hija.
        return "  ".repeat(nivel) + nombre() + " [" + volumen() + " m3] [" + peso() + " kg]\n";
    }

    @Override
    public String toString() {
        return mostrar(0);
    }
}

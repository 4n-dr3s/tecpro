// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Contenedor<T extends Guardable> extends Transportable implements Carga {
    Almacen<T> almacen;

    public Contenedor(double capacidad) {
        almacen = new Almacen<T>(capacidad);
    }

    public String nombre() {
        return "Contenedor";
    }

    public double volumen() {
        // Devuelve la capacidad del contenedor
        return almacen.volumen();
    }

    public double peso() {
        // Devuelve el peso del contenedor
        return almacen.peso();
    }

    public boolean guardar(T cargable) {
        // Guardamos un nuevo item en el contenedor
        return almacen.guardar(cargable);
    }

    public String tipo() {
        return "Contenedor";
    }

    @Override
    public String mostrar(int nivel) {
        // Mostramos los datos del contenedor, su tipo y listamos todo lo que contiene
        return "  ".repeat(nivel) + nombre() + " [" + volumen() + " m3] [" + peso() + " kg] de "
                + almacen.tipo() + "\n"
                + almacen.mostrar(nivel);
    }

}

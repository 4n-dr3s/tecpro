// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Camion {
    Almacen<Carga> almacen;

    public Camion(double capacidad) {
        almacen = new Almacen<Carga>(capacidad);
    }

    public String nombre() {
        return "Camion";
    }

    public double volumen() {
        // Devuelve la capacidad del camión
        return almacen.volumen();
    }

    public double peso() {
        // Devuelve el peso del camión
        return almacen.peso();
    }

    public boolean guardar(Carga cargable) {
        // Guardamos una nueva carga en el camión
        return almacen.guardar(cargable);
    }

    @Override
    public String toString() {
        // Mostramos el camión y todo lo que hay incluido en él
        return nombre() + " [" + volumen() + " m3] [" + peso() + " kg]\n" + almacen.mostrar(0);
    }
}

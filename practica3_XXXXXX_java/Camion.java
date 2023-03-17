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
        return almacen.volumen();
    }

    public double peso() {
        return almacen.peso();
    }

    public boolean guardar(Carga cargable) {
        return almacen.guardar(cargable);
    }

    @Override
    public String toString() {
        return "Camioncitoo";
    }
}

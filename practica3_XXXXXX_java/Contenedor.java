
public class Contenedor<T extends Guardable> extends Transportable implements Carga {
    Almacen<T> almacen;

    public Contenedor(double capacidad) {
        almacen = new Almacen<T>(capacidad);
    }

    public String nombre() {
        return "Contenedor";
    }

    public double volumen() {
        return almacen.volumen();
    }

    public double peso() {
        return almacen.peso();
    }

    public boolean guardar(T cargable) {
        return almacen.guardar(cargable);
    }

    @Override
    public String toString() {
        return nombre() + " [" + volumen() + " m3] [" + peso() + "kg]\n" + almacen.mostrar();
    }

}

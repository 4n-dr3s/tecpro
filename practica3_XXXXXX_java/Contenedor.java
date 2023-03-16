// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Contenedor<T extends Cargable> extends Cargable implements Transportable {
    Deposito almacen;
    
    public Contenedor(double capacidad) {
        almacen = new Deposito(capacidad);
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

    public void guardar(T cargable) {
        almacen.guardar(cargable);
    }
    
}

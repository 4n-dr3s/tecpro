import java.util.List;

// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Almacen<T extends Guardable> {
    protected List<T> items;
    protected double capacidad;

    public Almacen(double capacidad) {
        this.capacidad = capacidad;
    }

    public double volumen() {
        double total = 0;
        // Iteramos por cada elemento almacenado en el deposito
        if (!items.isEmpty()) {
            for (T i : items) {
                // Sumamos el volumen de ese elemento al total
                total += i.volumen();
            }
        }
        // Devolvemos el volumen total ocupado
        return total;
    }

    public double peso() {
        double total = 0;
        // Iteramos por cada elemento almacenado en el deposito
        if (!items.isEmpty()) {
            for (T i : items) {
                // Sumamos el volumen de ese elemento al total
                total += i.peso();
            }
        }
        // Devolvemos el volumen total ocupado
        return total;
    }

    public boolean guardar(T t) {
        // Calculamos el volumen actual
        if (this.volumen() + t.volumen() <= capacidad) {
            items.add(t);
            return true;
        } else {
            return false;
        }
    }
}

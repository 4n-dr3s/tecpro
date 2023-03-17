// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

import java.util.List;

// Deposito define objetos en los que se pueden guardar otros objetos
public class Deposito {
    protected List<Guardable> items;
    protected double capacidad;

    public Deposito(double capacidad) {
        this.capacidad = capacidad;
    }

    public double volumen() {
        double total = 0;
        // Iteramos por cada elemento almacenado en el deposito
        for (Guardable i : items) {
            // Sumamos el volumen de ese elemento al total
            total += i.volumen();
        }
        // Devolvemos el volumen total ocupado
        return total;
    }

    public double peso() {
        double total = 0;
        // Iteramos por cada elemento almacenado en el deposito
        for (Guardable i : items) {
            // Sumamos el volumen de ese elemento al total
            total += i.peso();
        }
        // Devolvemos el volumen total ocupado
        return total;
    }

    public void guardar(Guardable t) {
        // Calculamos el volumen actual
        if (this.volumen() + t.volumen() <= capacidad) {
            items.add(t);
        }
    }
}
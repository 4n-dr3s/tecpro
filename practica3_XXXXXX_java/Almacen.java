import java.util.ArrayList;

// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Almacen<T extends Guardable> {
    protected ArrayList<T> items;
    protected double capacidad;
    protected double volumen;
    protected double peso;

    public Almacen(double capacidad) {
        this.capacidad = capacidad;
        items = new ArrayList<T>();
    }

    public double volumen() {
        return capacidad;
    }

    public double peso() {
        return peso;
    }

    public boolean guardar(T t) {
        // Calculamos el volumen actual
        if (volumen + t.volumen() <= capacidad) {
            items.add(t);
            volumen += t.volumen();
            peso += t.peso();
            // System.out.println(this.nombre() + " " + this.volumen());
            return true;
        } else {
            return false;
        }
    }

    public String mostrar() {
        String cadena = "";
        for (T i : items) {
            cadena += " " + i.nombre() + "\n";
        }
        return cadena;
    }
}

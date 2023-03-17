// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

import java.util.ArrayList;

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
        // Devueve la capacidad del almacen
        return capacidad;
    }

    public double peso() {
        // Devuelve el peso del almacen
        return peso;
    }

    public boolean guardar(T t) {
        // Si cabe un nuevo item por volumen
        if (volumen + t.volumen() <= capacidad) {
            // Lo añadimos y sumamos su peso y volumen al del almacen
            items.add(t);
            volumen += t.volumen();
            peso += t.peso();
            // System.out.println(this.nombre() + " " + this.volumen());
            return true;
        } else {
            return false;
        }
    }

    public String tipo() {
        // Si la lista no es vacía, devolvemos el tipo de los items de la lista
        if (items.isEmpty()) {
            return "Vacío";
        } else {
            return items.get(0).tipo();
        }
    }

    public String mostrar(int nivel) {
        String cadena = "";
        // Mostramos cada uno de los elementos del almacén
        for (T i : items) {
            cadena += i.mostrar(nivel + 1);
        }
        return cadena;
    }
}

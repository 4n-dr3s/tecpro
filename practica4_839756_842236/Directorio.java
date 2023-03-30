import java.util.ArrayList;

public class Directorio extends Nodo{
    private ArrayList<Nodo> hijos;

    // Construimos el nodo con el nombre del directorio
    public Directorio(String nombre, Nodo padre) {
        super(nombre, padre);
        hijos = new ArrayList<Nodo>();
    }

    public String ls() {
        String resultado = "";
        for (Nodo h : hijos) {
            resultado += (h.getNombre() + "\n");
        }
        return resultado;
    }

    public void mkdir(String nombre, Nodo padre) {
        hijos.add(new Directorio(nombre, padre));
    }
}

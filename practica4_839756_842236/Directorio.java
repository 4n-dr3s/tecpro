import java.util.ArrayList;

public class Directorio extends Nodo {
    private ArrayList<Nodo> hijos;

    // Construimos el nodo con el nombre del directorio
    public Directorio(String name, Directorio parentNode) {
        super(name, parentNode);
        hijos = new ArrayList<Nodo>();
    }

    // Comprobar si existe un nodo hijo llamado "name"
    public Nodo existeNodo(String name) {
        Nodo resultado = null;
        for (Nodo i : hijos) {
            System.out.println(i.getName());
            System.out.println(name);
            if (i.getName().equals(name)) {
                resultado = i;
                break;
            }
        }
        return resultado;
    }

    public String ls() {
        String resultado = " ";
        for (Nodo h : hijos) {
            resultado += (h.getName() + '\n');
        }
        return resultado;
    }

    public void mkdir(String name, Directorio parentNode) {
        // ERROR!!
        hijos.add(new Directorio(name, parentNode));
    }

    public void vi(String name, Directorio parentNode, int size) {
        hijos.add(new Fichero(name, parentNode, size));
    }
}

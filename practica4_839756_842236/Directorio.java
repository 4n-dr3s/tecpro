import java.util.ArrayList;

public class Directorio extends Nodo {
    private ArrayList<Nodo> children;

    // Construimos el nodo con el nombre del directorio
    public Directorio(String name, Directorio parentNode) {
        super(name, parentNode);
        children = new ArrayList<Nodo>();
    }

    // Comprobar si existe un nodo hijo llamado "name"
    public Nodo existeNodo(String name) {
        Nodo resultado = null;
        // Iteramos por todos los hijos
        for (Nodo i : children) {
            // Si coincide el nombre, hacemos que resultado apunte al nodo
            if (i.getName().equals(name)) {
                resultado = i;
                break;
            }
        }
        return resultado;
    }

    @Override
    public int getSize() {
        int resultado = 0;
        // Se recorren todos los archivos del directorio
        for (Nodo i : children) {
            resultado += i.getSize();
        }
        // Se devuelve la suma total de todos los archivos del directorio
        return resultado;
    }

    public void removeAllChildren() {
        // Se itera por todos los hijos
        for (Nodo i : children) {
            // Si es un directorio
            if (i instanceof Directorio) {
                // Eliminamos todos los hijos de ese directorio
                ((Directorio) i).removeAllChildren();
            }
            // Eliminamos el nodo actual de la iteración
            children.remove(i);
        }
    }

    public void removeChild(Nodo n) {
        // Se elimna un nodo en concreto que se encontraba en la lista del directorio
        children.remove(n);
    }

    public String ls() {
        String resultado = "";
        // Se recorren todos los hijos
        for (Nodo h : children) {
            // Se añade su nombre al resultado
            resultado += (h.getName() + '\n');
        }
        return resultado;
    }

    public String du() {
        String resultado = "";
        // Se recorren todos los hijos
        for (Nodo h : children) {
            // Se añade su nombre y tamaño al resultado
            resultado += (h.getName() + " " + h.getSize() + '\n');
        }
        return resultado;
    }

    public void mkdir(String name, Directorio parentNode) {
        // Se crea y añade un directorio a la lista de hijos
        children.add(new Directorio(name, parentNode));
    }

    public void vi(String name, Directorio parentNode, int size) {
        // Se crea y añade un fichero a la lista de hijos
        children.add(new Fichero(name, parentNode, size));
    }

    public void ln(String name, Directorio parentNode, Nodo referenced) {
        // Se crea y añade un enlace a la lista de hijos
        children.add(new Enlace(name, parentNode, referenced));
    }
}

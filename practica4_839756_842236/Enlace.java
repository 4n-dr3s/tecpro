// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Enlace extends Nodo {
    private Nodo referenced;

    public Enlace(String nombre, Directorio parentNode, Nodo referenced) {
        super(nombre, parentNode);
        this.referenced = referenced;
    }

    public Nodo getReferenced() {
        // Devuelve el nodo al que hace referencia
        return referenced;
    }

    @Override
    public int getSize() {
        Directorio parent = parentNode;
        // Iteramos por cada uno de los padres
        while (parent != null) {
            // Comprobamos si el enlace apunta a algún nodo padre
            if (parent == referenced) {
                // Si es así devolvemos 0 como peso
                return 0;
            }
            parent = parent.getParent();
        }
        // Si el enlace no apunta a ningún padre,
        // devolvemos el tamaño del nodoreferenciado
        return referenced.getSize();
    }
}
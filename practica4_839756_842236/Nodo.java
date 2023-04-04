abstract class Nodo {

    protected Directorio parentNode;
    protected String name;

    public Nodo(String name, Directorio parentNode) {
        this.name = name;
        this.parentNode = parentNode;
    }

    public Directorio getParent() {
        // Devuelve el padre del nodo
        return parentNode;
    }

    public String getName() {
        // Devuelve el nombre del nodo
        return name;
    }

    // Devuelve la ruta actual
    public String pwd() {
        // Si no hay padre
        if (parentNode == null) {
            // Se devuelve carácter vacío
            return "";
        } else {
            // En caso contrario se busca la ruta del padre,
            // y se concatena el nombre del nodo actual
            return parentNode.pwd() + "/" + name;
        }
    }

    // Directorio, Enlace y Fichero hacen override de este método
    public int getSize() {
        // Por defecto devuelve que el tamaño es 0
        return 0;
    }
}

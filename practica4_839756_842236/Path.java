public class Path {
    private Directorio wd; // Working directory del path
    private Fichero file; // Fichero al que apunta el path

    public Path(String path, Directorio root, Directorio _wd) {
        // Inicialmente suponemos que el path no apunta a un fichero
        file = null;
        // Si la ruta es absoluta
        if (path.charAt(0) == '/') {
            // Establecemos la raíz como directorio de trabajo
            wd = root;
            // Prescindimos del primer carácter "/"
            path = path.substring(1);
        } else {
            // Sino wd
            wd = _wd;
        }
        // Separamos la lista en "/"
        String[] lista = path.split("/");
        for (int i = 0; i < lista.length; i++) {
            System.out.println("Trabajamos con " + lista[i]);
            if (lista[i].equals("..")) { // Si aparece ".."
                // Movemos el directorio de trabajo al padre
                wd = wd.getParent();
            } else if (!lista[i].equals(".")) { // Si no aparece "."
                Nodo hijo = wd.existeNodo(lista[i]);
                // Comprobamos si existe un nodo hijo en el wd actual
                if (hijo != null) {
                    // Comprobamos si el hijo es un directorio
                    if (hijo instanceof Directorio) {
                        // Desplazamos el wd al hijo
                        wd = (Directorio) hijo;
                    } else { // El hijo es un fichero
                        // Si es el último elemento de la lista
                        if (i == lista.length - 1) {
                            file = (Fichero) hijo;
                            System.out.println("Fichero en el último elemento del path");
                        } /*
                           * else { // Fichero en medio del path
                           * throw Exception;
                           * }
                           */
                    }
                } /*
                   * else { // No existe el nodo hijo
                   * throw Exception;
                   * }
                   */
            }
        }
    }

    // Devuelve el directorio de trabajo indicado por el path
    public Directorio getWd() {
        return wd;
    }

    // Devuelve el fichero al que apunta el path (null si no apunta a un fichero)
    public Fichero getFile() {
        return file;
    }
}
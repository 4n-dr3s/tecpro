public class Path {
    private Directorio wd; // Working directory del path
    private Fichero file; // Fichero al que apunta el path
    private final int limit = 10; // Limite de veces que un enlace puede apuntar a otro

    public Path(String path, Directorio root, Directorio _wd) throws ExcepcionArbolFicheros {
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
        // Si el primer elemento no está vacío
        if (lista[0].length() != 0) {
            for (int i = 0; i < lista.length; i++) {
                // System.out.println("Trabajamos con " + lista[i]);
                if (lista[i].equals("..")) { // Si aparece ".."
                    // Movemos el directorio de trabajo al padre
                    wd = wd.getParent();
                    if (wd == null) {
                        throw new ExcepcionArbolFicheros(
                                "Fuera de los límites. No existe el nodo padre");
                    }
                } else if (!lista[i].equals(".")) { // Si no aparece "."
                    Nodo hijo = wd.existeNodo(lista[i]);
                    // Comprobamos si existe un nodo hijo en el wd actual
                    if (hijo != null) {
                        // Comprobamos si el hijo es un directorio
                        if (hijo instanceof Directorio) {
                            // Desplazamos el wd al hijo
                            wd = (Directorio) hijo;
                        } else if (hijo instanceof Enlace) {
                            // Nodo referenciado por el enlace
                            Nodo r = ((Enlace) hijo).getReferenced();
                            // Mientras el nodo referenciado siga siendo un enlace
                            int counter = 0;
                            while (r instanceof Enlace && counter < limit) {
                                // Tomamos el nodo al que apunta
                                r = ((Enlace) r).getReferenced();
                                counter++;
                            }
                            // Si no nos se ha pasado del límite
                            if (counter < limit) {
                                // Se comprueba si r es un fichero
                                if (r instanceof Fichero) {
                                    // Se asigna r a file
                                    file = (Fichero) r;
                                } else {
                                    // Se asigna r al directorio de trabajo
                                    wd = (Directorio) r;
                                }
                            } else {
                                /* Error throw exception demasiados enlaces que apuntan a enlaces */
                                throw new ExcepcionArbolFicheros("Limite de referencias alcanzado");
                            }

                        } else { // El hijo es un fichero
                                 // Si es el último elemento de la lista
                            if (i == lista.length - 1) {
                                file = (Fichero) hijo;
                                // System.out.println("Fichero en el último elemento del path");
                            } else { // Fichero en medio del path
                                throw new ExcepcionArbolFicheros(
                                        "Se ha encontrado el fichero " + lista[i] + " en medio del path");
                            }
                        }
                    } else { // No existe el nodo hijo
                        throw new ExcepcionArbolFicheros("No existe el nodo al que apunta el path");
                    }
                }
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

    // Devuelve el nodo apuntado por el path
    public Nodo getNode() {
        // Si el path no apunta a un fichero
        if (file == null) {
            // Devolvemos el directorio de trabajo
            return wd;
        } else {
            // Devolvemos el fichero al que apunta el path
            return file;
        }
    }
}
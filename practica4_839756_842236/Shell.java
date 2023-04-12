// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Shell {
    private Directorio root; // Raíz del sistema de ficheros
    private Directorio wd; // Working directory

    public Shell() {
        root = new Directorio("", null);
        wd = root;
    }

    // Se devuelve ruta actual
    public String pwd() {
        // Si el directorio de trabajo es la raíz
        if (wd == root) {
            // Se devuelve "/"
            return "/";
        } else {
            // Sino se calcula la ruta actual
            return wd.pwd();
        }
    }

    // Lista el contenido del directorio de trabajo
    public String ls() {
        return wd.ls();
    }

    // Lista el contenido y el tamaño de los nodos contenidos
    // en el directorio de trabajo
    public String du() {
        return wd.du();
    }

    // Crea un fichero
    public void vi(String name, int size) throws ExcepcionArbolFicheros {
        Nodo n = wd.existeNodo(name);
        // No existe nodo con ese nombre
        if (n == null) {
            // Creamos fichero y lo añadimos al wd
            wd.vi(name, wd, size);
        } else {
            // Comprobamos que n es un fichero
            if (n instanceof Fichero) {
                ((Fichero) n).setSize(size);
            } else {
                throw new ExcepcionNoEsFichero();
            }
        }

    }

    // Se crea un directorio
    public void mkdir(String name) throws ExcepcionArbolFicheros {
        // Si no existe nodo con ese nombre
        if (wd.existeNodo(name) == null) {
            // Se crea el directorio
            wd.mkdir(name, wd);
        } else {
            throw new ExcepcionYaExisteDirectorio();
        }
    }

    // Permite mover el directorio de trabajo al path especificado
    public void cd(String path) throws ExcepcionArbolFicheros {
        Path p = new Path(path, root, wd);
        // Si p no apunta a un fichero
        if (p.getFile() == null) {
            // Nos movemos al directorio
            wd = p.getWd();
            System.out.println(wd.getName());
        } else {
            throw new ExcepcionApuntarFichero();
        }

    }

    // Crea un enlace
    public void ln(String path, String name) throws ExcepcionArbolFicheros {
        // Se crea un ruta a partir del path
        Path p = new Path(path, root, wd);
        // Nodo referenciado
        Nodo n = p.getNode();
        // Crea un enlace en el directorio de trabajo
        wd.ln(name, wd, n);
    }

    public int stat(String path) throws ExcepcionArbolFicheros {
        // Se crea un ruta a partir del path
        Path p = new Path(path, root, wd);
        // Se calcula el tamaño del nodo
        return p.getNode().getSize();
    }

    private boolean esBorradoErroneo(Directorio n, Directorio wdir) {
        Directorio aux = wdir;
        // Iteramos por cada uno de los padres de wd, empezando por él mismo
        while (aux != null) {
            // Comprobamos si el directorio que queremos
            // eliminar coincide co wd o sus padres
            if (aux == n) {
                // Si es así devolvemos true (borrado erróneo)
                return true;
            }
            // Tomamos el padre
            aux = aux.getParent();
        }
        return false;
    }

    public void rm(String path) throws ExcepcionArbolFicheros {
        // Se crea un ruta a partir del path
        Path p = new Path(path, root, wd);
        Nodo n = p.getNode();
        // Si no se quiere eliminar root
        if (n != root) {
            // Si el nodo al que se apunta es un directorio
            if (n instanceof Directorio) {
                // Nos aseguramos de que no eliminamos el wd o alguno de sus padres
                if (!esBorradoErroneo((Directorio) n, wd)) {
                    // Se eliminan todos los nodos dentro del directorio
                    ((Directorio) n).removeAllChildren();
                } else {
                    throw new ExcepcionEliminarWd();
                }
            }
            // Se elimina al propio nodo apuntado por el path
            n.getParent().removeChild(n);
        } else {
            throw new ExcepcionEliminarRoot();
        }

    }
}

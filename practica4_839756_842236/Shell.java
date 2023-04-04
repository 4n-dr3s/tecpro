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
                throw new ExcepcionArbolFicheros("No es un fichero");
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
            throw new ExcepcionArbolFicheros("Ya existe un directorio con ese nombre");
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
            throw new ExcepcionArbolFicheros("No se puede apuntar a un fichero");
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

    public void rm(String path) throws ExcepcionArbolFicheros {
        // Se crea un ruta a partir del path
        Path p = new Path(path, root, wd);
        Nodo n = p.getNode();
        // Si el nodo al que se apunta es un directorio
        if (n instanceof Directorio) {
            // Se eliminan todos los nodos dentro del directorio
            ((Directorio) n).removeAllChildren();
        }
        // Se elimina al propio nodo apuntado por el path
        n.getParent().removeChild(n);
    }
}

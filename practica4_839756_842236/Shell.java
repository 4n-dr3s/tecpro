public class Shell {
    private Directorio root; // Raíz del sistema de ficheros
    private Directorio wd; // Working directory

    public Shell() {
        root = new Directorio("", null);
        wd = root;
    }

    public String pwd() {
        if (wd == root) {
            return "/";
        } else {
            return wd.pwd();
        }
    }

    public String ls() {
        return wd.ls();
    }

    public String du() {
        return "Duuuu!!";
    }

    public void vi(String name, int size) {
        Nodo n = wd.existeNodo(name);
        // No existe nodo con ese nombre
        if (n == null) {
            // Creamos fichero y lo añadimos al wd
            wd.vi(name, wd, size);
        } else {
            // Comprobamos que n es un fichero
            if (n instanceof Fichero) {
                ((Fichero) n).setSize(size);
            } /*
               * else {
               * throw Exception "No es un fichero"
               * }
               */
        }

    }

    public void mkdir(String name) {
        if (wd.existeNodo(name) == null) {
            wd.mkdir(name, wd);
        } /*
           * throw Exception "Ya existe un nodo con ese nombre"
           */
    }

    public void cd(String path) {
        Path p = new Path(path, root, wd);
        // Si p no apunta a un fichero
        if (p.getFile() == null) {
            // Nos movemos al directorio
            wd = p.getWd();
            System.out.println(wd.getName());
        } /*
           * else { // cd no puede apuntar a un fichero
           * throw Exception
           * }
           */

    }

    public void ln(String path, String name) {
    }

    public int stat(String path) {
        return 33;
    }

    public void rm(String path) {
    }
}

// /lib/bin/fichero.txt
// [lib, bin, fichero.txt]

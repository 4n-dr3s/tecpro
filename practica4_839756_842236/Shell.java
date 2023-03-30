public class Shell {
    private Directorio raiz; // Raíz del sistema de ficheros
    private Directorio wd; // Working directory

    public Shell() {
        raiz = new Directorio("", null);
        wd = raiz;
    }

    public String pwd() {
        if (wd == raiz) {
            return "/";
        }
        else {
            return wd.pwd();
        }
    }

    public String ls() {
        return wd.ls();
    }

    public void mkdir(String nombre) {
        wd.mkdir(nombre, wd);
    }
}


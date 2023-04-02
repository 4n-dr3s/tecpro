public class Nodo {

    protected Directorio parentNode;
    protected String name;

    public Nodo(String name, Directorio parentNode) {
        this.name = name;
        this.parentNode = parentNode;
    }

    public Directorio getParent() {
        return parentNode;
    }

    public String getName() {
        return name;
    }

    public String pwd() {
        if (parentNode == null) {
            return "";
        } else {
            return parentNode.pwd() + "/" + name;
        }
    }
}

public class Enlace extends Nodo {
    Nodo referenced;

    public Enlace(String nombre, Directorio parentNode, Nodo referenced) {
        super(nombre, parentNode);
        this.referenced = referenced;
    }
}
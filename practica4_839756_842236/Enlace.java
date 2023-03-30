public class Enlace extends Nodo {
    Nodo referenciado;
    
    public Enlace(String nombre, Nodo padre, Nodo referenciado){
        super(nombre, padre);
        this.referenciado = referenciado;
    }
}
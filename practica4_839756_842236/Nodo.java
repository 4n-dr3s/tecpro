public class Nodo {

    protected Nodo padre;
    protected String nombre;

    public Nodo(String nombre, Nodo padre) {
        this.nombre = nombre;
        this.padre = padre;
    }

    public String getNombre() {
        return nombre;
    }

    public String pwd(){
        if (padre == null) {
            return "";
        } else {
            return padre.pwd() + "/" + nombre;
        }
    }
}

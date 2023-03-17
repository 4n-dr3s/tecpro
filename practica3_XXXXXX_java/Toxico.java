// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class Toxico extends Transportable {

    public Toxico(String nombre, double volumen, double peso) {
        this.nombre = nombre;
        this.volumen = volumen;
        this.peso = peso;
    }

    public String tipo() {
        return "Productos Toxicos";
    }

}

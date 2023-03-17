// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class SerVivo extends Transportable {

    public SerVivo(String nombre, double volumen, double peso) {
        this.nombre = nombre;
        this.volumen = volumen;
        this.peso = peso;
    }

    public String tipo() {
        return "Seres Vivos";
    }

}

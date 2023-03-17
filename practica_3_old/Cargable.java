// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

// Cargable define todo tipo de objetos susceptibles de ser cargados en un camión
abstract class Cargable implements Guardable {

    protected String nombre;
    protected double volumen;
    protected double peso;

    public String nombre() {
        return nombre;
    }

    public double volumen() {
        return volumen;
    }

    public double peso() {
        return peso;
    }

}

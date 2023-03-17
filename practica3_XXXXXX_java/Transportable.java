// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

abstract class Transportable implements Guardable {

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

    @Override
    public String toString() {
        return nombre() + " [" + volumen() + " m3] [" + peso() + "kg]\n" + nombre();
    }
}

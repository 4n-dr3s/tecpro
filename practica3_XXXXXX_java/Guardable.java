// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

// La interfaz Guardable representa objetos que pueden ser guardados en un objeto de tipo Almacen
public interface Guardable {
    public String nombre();

    public double volumen();

    public double peso();

    public String tipo();

    public String mostrar(int nivel);
}

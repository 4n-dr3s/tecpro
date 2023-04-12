// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class ExcepcionFicheroComoDirectorio extends ExcepcionArbolFicheros {
    public ExcepcionFicheroComoDirectorio() {
        super("Se ha encontrado un fichero en medio del path");
    }
}

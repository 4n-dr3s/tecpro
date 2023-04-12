// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class ExcepcionYaExisteDirectorio extends ExcepcionArbolFicheros {
    public ExcepcionYaExisteDirectorio() {
        super("Ya existe un directorio con ese nombre");
    }
}

// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

public class ExcepcionEliminarWd extends ExcepcionArbolFicheros {
    public ExcepcionEliminarWd() {
        super("No se puede eliminar el directorio de trabajo actual o alguno de sus padres");
    }
}

public class Fichero extends Nodo{
   private int size;

   // Construimos el nodo con el nombre del fichero
   public Fichero(String nombre, Nodo padre, int size){
      super(nombre, padre);
      this.size = size;
   }
}

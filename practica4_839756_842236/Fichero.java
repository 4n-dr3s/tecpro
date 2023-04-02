public class Fichero extends Nodo {
   private int size;

   // Construimos el nodo con el nombre del fichero
   public Fichero(String name, Directorio parentNode, int size) {
      super(name, parentNode);
      this.size = size;
   }

   public void setSize(int size) {
      this.size = size;
   }

   public int getSize() {
      return size;
   }
}

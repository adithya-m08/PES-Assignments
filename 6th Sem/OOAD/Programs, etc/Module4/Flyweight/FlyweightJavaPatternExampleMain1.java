public class FlyweightJavaPatternExampleMain1 {

   static CarFactory carFactory = new CarFactory();

   public static void main(String[] args) {

      for (int x = 1; x < 5; x = x + 1) {
         Car car1 = carFactory.getCar("Chevrolet");
         System.out.println("A Chevrolet car was drawn in position (x, y)=(" + x + ",10)");
      }

      for (int x = 1; x < 5; x = x + 1) {
         Car car1 = carFactory.getCar("BMW");
         System.out.println("A BMW car was drawn in position (x, y)=(" + x + ",10)");
      }

   }

}
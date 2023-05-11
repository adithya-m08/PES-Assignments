//If you make any method as final, you cannot override it.

class Bike{  
  final void run(){System.out.println("running");}  
}  
     
class Honda extends Bike{  
   void run(){System.out.println("running safely with 100kmph");}  
     
   public static void finalmethod(String args[]){  
   Honda honda= new Honda();  
   honda.run();  
   }  
}  
import java.util.HashMap; 
 class CarFactory {
 
    private HashMap<String, Car> carsList = new HashMap<String, Car>();
     
    public Car getCar(String carType) {
         
        Car car = carsList.get(carType);
         
        if (car == null) {
            if (carType == "Chevrolet") {
                car = new Chevrolet();
                carsList.put("Chevrolet", car);
                System.out.println("A Chevrolet car was CREATED and saved in memory");
                 
            } else if (carType == "BMW") {
                car = new BMW();
                carsList.put("BMW", car);
                System.out.println("A BMW car was CREATED and saved in memory");
                 
            } else if (carType == "Renault") {
                car = new Renault();
                carsList.put("Renault", car);
                System.out.println("A Renault car was CREATED and saved in memory");
            }
 
        }
 
        return car;
    }   
}


 interface Car {
 
  // This method build a car.
  public void build();
}

 class Chevrolet implements Car{
      
    public void build(){
        System.out.println("A Chevrolet car has been built.");
    }
     
}

class BMW implements Car{
      
    public void build(){
        System.out.println("A BMW car has been built.");
    }
     
}

class Renault implements Car{
      
    public void build(){
        System.out.println("A Renault car has been built.");
    }
     
}







package factoryDesignPatternDemo;

//The Factory (Logics And Procedure)
public abstract class Factory 
{
    public Car create(String requestedGrade) 
    {
        Car car = retrieveCar(requestedGrade);
        car = prepareCar(car);
        return car;
    }
    
    private Car prepareCar(Car car)
    {
        car.clean();
        car.mechanicCheck();
        car.fuelCar();
        return car;
    }
    abstract Car retrieveCar(String requestedGrade);
}
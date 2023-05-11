package factoryDesignPatternDemo;

//The Products (Cars)
public abstract class Car {
	public int horsePower;
    public String fuelSource;
    public String color;
    public void startEngine(){
        System.out.println("The " + fuelSource + " engine has been started, and is ready to utilize " + horsePower + " horsepowers.n" );
    }
    public void clean(){
        System.out.println("Car has been cleaned, and the " + color.toLowerCase() + " color shines");
    }
    public void mechanicCheck(){
        System.out.println("Car has been checked by the mechanic. Everything looks good!");
    }
    public void fuelCar(){
        System.out.println("Car is being filled with " + fuelSource.toLowerCase());
    }
}

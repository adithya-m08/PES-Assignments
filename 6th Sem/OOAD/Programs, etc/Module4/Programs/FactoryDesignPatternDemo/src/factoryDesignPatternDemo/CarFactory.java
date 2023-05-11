package factoryDesignPatternDemo;

public class CarFactory extends Factory {

	
	    Car retrieveCar(String requestedGrade) {
	        switch (requestedGrade) {
	            case "A":
	                return new Maruti();
	            case "B":
	                return new Tayota();
	            default:
	                System.out.println("The requested car was unfortunately not available.");
	                return null;
	        }
	    
}}

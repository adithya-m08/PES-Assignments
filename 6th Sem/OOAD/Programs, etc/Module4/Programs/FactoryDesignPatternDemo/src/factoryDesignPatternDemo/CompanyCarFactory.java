package factoryDesignPatternDemo;



public class CompanyCarFactory extends Factory {
    @Override
    Car retrieveCar(String requestedGrade) {
        switch (requestedGrade) {
            case "A":
                return new Tesla();
            case "B":
                return new Audi();
            default:
                System.out.println("The requested car was unfortunately not available.");
                return null;
        }
    }
}

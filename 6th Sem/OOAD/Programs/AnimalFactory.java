package OOAD;

public class AnimalFactory {
    public Animal getAnimal(String animalType) {
        if (animalType == null) {
            return null;
        }
        if (animalType.equalsIgnoreCase("dog")) {
            return new Dog();
        } else if (animalType.equalsIgnoreCase("cat")) {
            return new Cat();
        }
        return null;
    }
}

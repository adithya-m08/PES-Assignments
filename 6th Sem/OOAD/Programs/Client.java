package OOAD;

public class Client {
    public static void main(String[] args) {
        AnimalFactory animalFactory = new AnimalFactory();
        Animal animal1 = animalFactory.getAnimal("dog");
        animal1.eat();
        Animal animal2 = animalFactory.getAnimal("cat");
        animal2.eat();

        Animal animal3 = animalFactory.getAnimal("dog");
        animal3.eat();
    }
}

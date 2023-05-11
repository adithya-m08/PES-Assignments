public class Client {
    public static void main(String[] args) {
        AnimalFactory animalFactory = new AnimalFactory();
      
        Animal animal = animalFactory.getAnimal("dog");
        animal.eat();
      
        Animal animal2 = animalFactory.getAnimal("CAT");
        animal2.eat();
      
        Animal animal3 = animalFactory.getAnimal("raBbIt");
        animal3.eat();
    }
}

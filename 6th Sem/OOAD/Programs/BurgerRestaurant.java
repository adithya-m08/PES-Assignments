package Programs;

public class BurgerRestaurant {
    public static void main(String[] args) {
        BurgerBuilder burgerBuilder = new BurgerBuilder();
        Burger burger = burgerBuilder.build();
        burger.print();
    }
}

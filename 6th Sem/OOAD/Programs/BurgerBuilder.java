package Programs;

public abstract class BurgerBuilder {
    Burger burger = new Burger();

    abstract void buildBun();

    abstract void buildSalad();

    abstract void buildCheese();

    abstract void buildSauce();

    Burger build() {
        return burger;
    }
}

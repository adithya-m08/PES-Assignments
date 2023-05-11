package builderPatternDemo;

//How To Use The Builder Pattern
public class MainBuilderPattern {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BurgerResuturant burgerResuturant = new BurgerResuturant();
        burgerResuturant.setBuilder(new CheeseBurgerBuilder());
        buildBurger(burgerResuturant);
        //burgerResuturant.setBuilder(new VeganBurgerBuilder());
        //buildBurger(burgerResuturant);

	}
	
	private static void buildBurger(BurgerResuturant burgerResuturant) {
        Burger burger = burgerResuturant.buildBurger();
        burger.print();
    }

}

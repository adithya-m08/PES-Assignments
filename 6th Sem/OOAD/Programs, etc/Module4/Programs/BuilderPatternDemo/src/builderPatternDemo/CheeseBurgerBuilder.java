package builderPatternDemo;

public class CheeseBurgerBuilder extends BurgerBuilder {
   
    public void buildBun() {
        burger.setBun("White Bread");
    }
    
    public void buildMeat() {
        burger.setMeat("Beef");
    }
    
    public void buildSalad() {
        burger.setSalad("Iceberg");
    }
   
    public void buildCheese() {
        burger.setCheese("American Cheese");
    }
    
    public void buildSauce() {
        burger.setSauce("Secret Sauce");
    }
}

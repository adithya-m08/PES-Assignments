public class StaticDemo {
    static int a=1,b;
    
    static void display(int x){
        System.out.println("x="+x);
        System.out.println("a="+a);
        System.out.println("b="+b);
    }
    
    static{
        System.out.println("Inside static block");
        b=a*2;
    }
    public static void main(String[] args) {
        System.out.println("Inside main");
        display(5);
    }
}


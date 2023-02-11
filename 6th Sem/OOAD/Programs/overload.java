class Addition{
    int add(int a, int b){
        return a+b;
    }
    int add(int a, int b, int c){
        return a+b+c;
    }
    double add(int a, double b){
        return a+b;
    }
    double add(double a, int b){
        return a+b;
    }
}
public class overload {
    public static void main(String[] args){
        Addition a = new Addition();
        System.out.println(a.add(1,2));
        System.out.println(a.add(1,2,3));
        System.out.println(a.add(1,2.0));
        System.out.println(a.add(1.0,2));
    }
}

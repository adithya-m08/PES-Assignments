//Factorial.java
public class Factorial {
  static int fact(int n){
        if(n==0)
            return 1;
        else return n*fact(n-1);
        
    }
    public static void main(String[] args) {
        int n=6;
        int res=fact(n);
        System.out.println(n+"!"+"="+res);
    }   
}

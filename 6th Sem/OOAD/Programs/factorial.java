import java.util.*;
public class factorial {
    int fact(int n){
        if(n==0)
            return 1;
        else
            return n*fact(n-1);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        factorial f = new factorial();
        System.out.println(f.fact(n));
        sc.close();
    }
}

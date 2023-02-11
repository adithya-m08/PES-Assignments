import java.util.Scanner;

public class Primes {
    private int a;
    private int b;

    public Primes(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    private boolean pno(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public void isPrime() {
        if (!pno(a) && !pno(b)) {
            System.out.println(0);
        } else if (pno(a) && !pno(b)) {
            System.out.println(1);
        } else if (!pno(a) && pno(b)) {
            System.out.println(2);
        } else if (pno(a) && pno(b)) {
            if (Math.abs(a - b) == 2) {
                System.out.println(4);
            } else {
                System.out.println(3);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        
        int b = sc.nextInt();
        Primes p = new Primes(a, b);
        p.isPrime();
        sc.close();
    }
}

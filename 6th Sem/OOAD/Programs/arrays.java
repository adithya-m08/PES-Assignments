import java.util.Scanner;

public class arrays {
    public static void main(String[] args) {
        System.out.println("enter size of array");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] myIntArray = new int[size];
        for (int i = 0; i < myIntArray.length; i++) {
            myIntArray[i] = sc.nextInt();
        }
        System.out.println("printing array");
        for (int i = 0; i < myIntArray.length; i++) {
            System.out.println(myIntArray[i]);
        }
        sc.close();
    }
}

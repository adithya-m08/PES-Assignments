import java.util.*;

public class arraylist {
    public static void main(String[] args) {
        ArrayList<Integer> list1 = new ArrayList<Integer>();
        ArrayList<String> list2 = new ArrayList<String>();
        ArrayList<Boolean> list3 = new ArrayList<Boolean>();
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        for (int i = 0; i < size; i++) {
            list1.add(sc.nextInt());
        }
        System.out.println("1. Add element to list at index");
        System.out.println("2. Remove element from list at index");

        list1.sort(null);
        System.out.println(list1);
    }
}

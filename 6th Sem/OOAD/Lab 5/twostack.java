import java.util.*;

public class twostack {
    int[] arr;
    int size;
    int s1top, s2top;

    public twostack(int n) {
        size = n;
        arr = new int[size];
        s1top = -1;
        s2top = size;
    }

    public void push1(int x) {
        if (s1top < s2top - 1) {
            s1top++;
            arr[s1top] = x;
        } else
            System.out.println("Stack1 Overflow");
    }

    public void push2(int x) {
        if (s1top < s2top - 1) {
            s2top--;
            arr[s2top] = x;
        } else
            System.out.println("Stack2 Overflow");
    }

    public void pop1() {
        if (s1top >= 0) {
            int x = arr[s1top];
            s1top--;
            System.out.println(x);
        } else
            System.out.println("Stack1 Underflow");
    }

    public void pop2() {
        if (s2top < size) {
            int x = arr[s2top];
            s2top++;
            System.out.println(x);
        } else {
            System.out.println("Stack2 Underflow");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int size = scanner.nextInt();
        twostack st = new twostack(size);

        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            String operation = scanner.next();
            if (operation.equals("push1")) {
                int x = scanner.nextInt();
                st.push1(x);
            } else if (operation.equals("push2")) {
                int x = scanner.nextInt();
                st.push2(x);
            } else if (operation.equals("pop1"))
                st.pop1();
            else if (operation.equals("pop2"))
                st.pop2();
        }

        System.out.println("fin");
    }
}

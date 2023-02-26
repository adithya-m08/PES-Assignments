import java.util.*;

public class postfixer {

    public static String infixToPostfix(String infix) {
        Stack<Character> st = new Stack<>();
        String postfix = "";

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);
            if (ch == ' ') {
                continue;
            } else if (Character.isLetterOrDigit(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.isEmpty() && st.peek() != '(') {
                    postfix += st.pop();
                }
                st.pop();
            } else {
                while (!st.isEmpty() && order(ch) <= order(st.peek())) {
                    postfix += st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.isEmpty()) {
            postfix += st.pop();
        }

        return postfix;
    }

    public static int order(char ch) {
        if (ch == '+' || ch == '-') {
            return 1;
        } else if (ch == '*' || ch == '/') {
            return 2;
        } else if (ch == '^') {
            return 3;
        } else {
            return -1;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String infix = sc.nextLine();
            System.out.println(infixToPostfix(infix));
        }
        sc.close();
    }
}

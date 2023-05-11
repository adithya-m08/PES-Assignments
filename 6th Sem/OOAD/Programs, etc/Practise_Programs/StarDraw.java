//StarDraw.java
public class StarDraw {

    static void drawStar(int n) {
        if (n == 1) {
            System.out.println("*");
        } else {
            System.out.print("*");
            drawStar(n - 1);
        }
    }

    public static void main(String[] args) {
        drawStar(5);
        drawStar(4);
        drawStar(3);
        drawStar(2);
        drawStar(1);
    }
}

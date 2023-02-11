class Box {
    double width;
    double height;
    double depth;

    Box() {
        width = 0.0;
        height = 0.0;
        depth = 0.0;
    }

    Box(int width, int height, int depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    Box(Box b1) {
        width = b1.width;
        height = b1.height;
        depth = b1.depth;
    }

    void disp() {
        System.out.println("width:" + width);
        System.out.println("height:" + height);
        System.out.println("depth:" + depth);

    }
}

class CttDemo {
    public static void main(String args[]) {
        Box b1 = new Box();
        Box b2 = new Box(10, 20, 30);
        Box b3 = new Box(b2);
        b1.disp();
        b2.disp();
        b3.disp();
    }
}
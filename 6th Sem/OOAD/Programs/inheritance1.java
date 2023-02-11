class A {
    int a;

    void methodA() {
        System.out.println("Method A" + a);
    }

    void methodC() {
        System.out.println("Class A method C");
    }
}

class B extends A {
    void methodB() {
        System.out.println("Method B");
    }

    void methodC() {
        System.out.println("Class B method C");
    }
}

public class inheritance1 {
    public static void main(String[] args) {
        A a = new A();
        a.methodA();
        a.methodC();
        
        B b = new B();
        b.methodA();
        b.methodB();
        b.methodC();
    }
}

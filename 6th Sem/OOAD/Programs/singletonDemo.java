public class singletonDemo {
    public static void main(String[] args) {
        LoggerSingleton logger1 = LoggerSingleton.getInstance();
        System.out.println(logger1);
        LoggerSingleton logger2 = LoggerSingleton.getInstance();
        System.out.println(logger2);
    }
} 
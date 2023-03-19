public class LoggerSingleton {
    private static LoggerSingleton instance = new LoggerSingleton();

    private LoggerSingleton() {
    }

    public static LoggerSingleton getInstance() {
        if(instance == null) {
            instance = new LoggerSingleton();
        }
        return instance;
    }
}
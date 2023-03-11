import java.io.*;

public class Application {
    public static void main(String[] args) {
        Config config = null;
        String filename = "config.cfg";

        File file = new File(filename);
        if (file.exists()) {
            try {
                FileInputStream fis = new FileInputStream(filename);
                ObjectInputStream ois = new ObjectInputStream(fis);
                config = (Config) ois.readObject();
                ois.close();
                fis.close();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            config = new Config();
        }

        config.put("Path", "C:\\Program Files\\Java\\jdk1.8.0_121\\bin");
        config.put("Version", "4.2.0");
        config.put("System_Name", "Adi-PC");

        config.serialize();

        System.out.println("Updated Config Values:");
        System.out.println("Path: " + config.get("Path"));
        System.out.println("Version: " + config.get("Version"));
        System.out.println("System_Name: " + config.get("System_Name"));
    }
}

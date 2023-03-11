import java.io.*;
import java.util.HashMap;

public class Config implements Serializable {
    private static final long serialVersionUID = 1L;
    private HashMap<String, String> map = new HashMap<>();

    public void put(String key, String value) {
        map.put(key, value);
    }

    public String get(String key) {
        return map.get(key);
    }

    public void serialize() {
        try {
            FileOutputStream fileOut = new FileOutputStream("config.cfg");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(this);
            out.close();
            fileOut.close();
        } catch (IOException i) {
            i.printStackTrace();
        }
    }

    public static Config deserialize() {
        Config config = null;
        try {
            FileInputStream fileIn = new FileInputStream("config.cfg");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            config = (Config) in.readObject();
            in.close();
            fileIn.close();
        } catch (IOException i) {
            i.printStackTrace();
        } catch (ClassNotFoundException c) {
            System.out.println("Config class not found");
            c.printStackTrace();
        }
        return config;
    }
}

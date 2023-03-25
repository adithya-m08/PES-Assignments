import java.net.*;

public class TestUser {

    public static void main(String args[]) throws UnknownHostException {

      System.out.println("User name is: " + System.getProperty("user.name") );
      InetAddress localHost = InetAddress.getLocalHost();
      System.out.println("IP Address is :" + localHost.getHostAddress());

    }

}

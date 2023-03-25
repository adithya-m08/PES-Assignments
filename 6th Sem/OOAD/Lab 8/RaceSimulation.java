import java.util.*;
import java.net.*;

public class RaceSimulation implements Runnable {
    public int id;
    public int distance;

    public RaceSimulation(int id) {
        this.id = id;
        this.distance = 0;
    }

    @Override
    public void run() {
        Random random = new Random();
        while (distance < 1000) {
            int distanceCovered = random.nextInt() % 5 + 5;
            distance += distanceCovered;
            System.out.println(id + " " + distance + "m");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(id + " has finished");
    }

    public static void main(String[] args) throws InterruptedException, UnknownHostException {
        System.out.println("User name is: " + System.getProperty("user.name"));
        InetAddress localHost = InetAddress.getLocalHost();
        System.out.println("IP Address is :" + localHost.getHostAddress());

        System.out.println("Enter number of runners");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        List<RaceSimulation> runners = new ArrayList<>();

        for (int i = 1; i <= num; i++) {
            runners.add(new RaceSimulation(i));
        }

        List<Thread> threads = new ArrayList<>();
        for (RaceSimulation runner : runners) {
            Thread thread = new Thread(runner);
            threads.add(thread);
            thread.start();
            if(runner.id == 3)
                thread.interrupt();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        runners.sort((o1, o2) -> Integer.compare(o2.distance, o1.distance));
        System.out.println("Top 3");
        for (int i = 0; i < 3 && i < runners.size(); i++) {
            System.out.println((i + 1) + ". " + runners.get(i).distance + " " +
                    runners.get(i).distance + " meters");
        }
        sc.close();    
    }
}

import java.util.*;

abstract class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    void sleep() {
        System.out.println(name + " is sleeping");
    }

    abstract void speak();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String[] line = sc.nextLine().split(" ");
            String a = line[0];
            String name = line[1];
            Animal animal = null;

            if (a.equals("LION")) {
                int speed = Integer.parseInt(line[2]);
                animal = new Lion(name, speed);
            } else if (a.equals("MONKEY")) {
                animal = new Monkey(name);
            } else if (a.equals("ELEPHANT")) {
                int weight = Integer.parseInt(line[2]);
                animal = new Elephant(name, weight);
            }

            String func = line[line.length - 1];

            if (func.equals("SLEEP")) {
                animal.sleep();
            } else if (func.equals("SPEAK")) {
                animal.speak();
            }
        }

        sc.close();
    }
}

class Lion extends Animal {
    int speed;

    Lion(String name, int speed) {
        super(name);
        this.speed = speed;
    }

    void sleep() {
        System.out.println(name + " is sleeping");
    }

    void speak() {
        System.out.println("I am a lion, my name is " + name + " and I am " + speed + "m/s fast");
    }
}

class Monkey extends Animal {
    Monkey(String name) {
        super(name);
    }

    void sleep() {
        System.out.println(name + " is sleeping");
    }

    void speak() {
        System.out.println("I am a monkey, my name is " + name);
    }
}

class Elephant extends Animal {
    int weight;

    Elephant(String name, int weight) {
        super(name);
        this.weight = weight;
    }

    void speak() {
        System.out.println("I am an elephant, my name is " + name + " and I weigh " + weight + " kgs");
    }
}
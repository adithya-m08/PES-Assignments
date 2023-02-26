import java.util.*;
public class Person {
    protected String name;
    protected int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void introduce() {
        System.out.println("My name is " + name + " and my age is " + age);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        int age = sc.nextInt();
        Person p = new Person(name, age);
        p.introduce();
        name = sc.next();
        age = sc.nextInt();
        int studentId = sc.nextInt();
        Student s = new Student(name, age, studentId);
        s.introduce();
        name = sc.next();
        age = sc.nextInt();
        studentId = sc.nextInt();
        String thesisTitle = sc.next();
        GraduateStudent gs = new GraduateStudent(name, age, studentId, thesisTitle);
        gs.introduce();
        name = sc.next();
        age = sc.nextInt();
        String subject = sc.next();
        Teacher t = new Teacher(name, age, subject);
        t.introduce();
        System.out.println("fin");
    }
}
class Student extends Person {
    protected int studentId;
    public Student(String name, int age, int studentId) {
        super(name, age);
        this.studentId = studentId;
    }
    public void introduce() {
        super.introduce();
        System.out.println("I am a student with student ID : " + studentId);
    }
}
class GraduateStudent extends Student {
    private String thesisTitle;
    public GraduateStudent(String name, int age, int studentId, String thesisTitle) {
        super(name, age, studentId);
        this.thesisTitle = thesisTitle;
    }
    public void introduce() {
        super.introduce();
        System.out.println("I am a graduate student and my thesis title is " + thesisTitle);
    }
}
class Teacher extends Person {
    private String subject;
    public Teacher(String name, int age, String subject) {
        super(name, age);
        this.subject = subject;
    }
    public void introduce() {
        super.introduce();
        System.out.println("I am a teacher and I teach " + subject);
    }
}
class Teacher {
    String designation = "Teacher";
    String collegeName = "PESU";

    void does() {
        System.out.println("Teaching");
    }
}

public class inheritance extends Teacher {
    String mainSubject = "Java";

    public static void main(String args[]) {
        inheritance obj = new inheritance();
        System.out.println(obj.collegeName);
        System.out.println(obj.designation);
        System.out.println(obj.mainSubject);
        obj.does();
    }
}

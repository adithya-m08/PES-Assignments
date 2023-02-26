public class comparing {
    public static void main(String[] args){
        objcomparison();
    }
    public static void objcomparison(){
        Object obj1 = new Object();
        Object obj2 = new Object();
        Object obj3 = obj1;
        System.out.println(obj1 == obj2);
        System.out.println(obj1.equals(obj2));
        System.out.println(obj1 == obj3);
        System.out.println(obj1.equals(obj3));
    }
    public static void StringComparison(){
        String str1=new String("Java");
        String str2=new String("JAVA");
        String str3="Java";
        String str4=str1;
        String str5="Java";
        System.out.println(str1==str2);
        System.out.println(str1==str3);
        System.out.println(str3==str5);
        System.out.println(
    }
}

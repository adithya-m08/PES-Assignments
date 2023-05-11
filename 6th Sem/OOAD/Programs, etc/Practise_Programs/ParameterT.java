


class parameter {
void testing(int data)
{
data = 50;
}
}


public class ParameterT
{
   public static void main(String[ ] args)
   { int data = 7;
parameter p1= new parameter();
System.out.println(data);
p1.testing(data);
System.out.println(data);

         }
}

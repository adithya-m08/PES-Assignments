interface write
{
void disp();
int c=10;
default void new()//added pri default 
{
System.out.println("i am a default method");
}
}
interface read
{
void disp();
}

class interfacedemo implements write, read
{
public void disp()
{
System.out.println("implementation of disp");
}
public static void main(String args[])
{
write r=new interfacedemo();
interfacedemo d=new interfacedemo();
r.disp();
System.out.println("value of r= "+r.c);
//r.c++;its final, static
d.disp();
System.out.println("value of r= "+d.c);
}
}
class A
{
int i;
}

class B extends A
{
int j;
}

class Demo2
{
public static void main(String args[])
{

A obj=new A();
B cobj=new B();
obj.i=10;
cobj.i=11;
cobj.j=12;

obj=cobj; // a baseclass variable can refer a derived class obj
System.out.println(obj.j);


}
}

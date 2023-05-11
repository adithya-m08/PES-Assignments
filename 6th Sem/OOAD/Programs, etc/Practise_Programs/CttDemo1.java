class rect
{
 int l;//instance variables
 int b;


rect()
{
//this(10,20);//parametrized ctt
l=b=0;
System.out.println("Default ctt");
}

rect(int l, int b)
{
this.l=l;//instance var are hidden by local variables.
this.b=b;
System.out.println("param ctt");
}

rect(rect t)
{
this.l=t.l;
this.b=t.b;
System.out.println("ctt with object as parameter");
}

}


class CttDemo1

{
public static void main(String args[])

{

rect r = new rect();
rect r1=new rect(10,20);

rect r2=new rect(r1);

System.out.println("Object info");

System.out.println(r.l);
System.out.println(r.b);

System.out.println(r1.l);
System.out.println(r1.b);

System.out.println(r2.l);
System.out.println(r2.b);

}
}

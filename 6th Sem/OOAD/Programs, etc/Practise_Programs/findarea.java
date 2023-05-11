abstract class shape
{
int d1;
int d2;
//u canot declare abstract  ctt or abstract static methods
shape(int a, int b)
{
d1=a;
d2=b;
}

abstract void calcarea();//abstract methods

void hellomethod()  //concrete method
{
System.out.println("hello im in class shape");
}

}

class rect extends shape
{
rect(int a,int b)
{
super(a,b);
}

void calcarea()
{
System.out.println("Area of rectangle= "+ (d1*d2));
}
//override toString() inherited from object class

public String toString()
{
return "dim1 of rect="+d1+" dim2= "+d2;
}

}

class triangle extends shape
{

triangle(int a, int b)
{
super(a,b);
}
void calcarea()
{
System.out.println("Area of trianle= "+ (0.5*d1*d2));
}

}

class findarea
{
public static void main(String args[])
{
//shape s=new shape(0,0);
shape s;
rect r=new rect(2,3);
System.out.println(r.d1);
System.out.println(r.d2);
System.out.println("after overriding tostring");
System.out.println(r);
triangle t=new triangle(3,4);
s=r;
s.hellomethod();
r.calcarea();
t.calcarea();
r.hellomethod();

}
}


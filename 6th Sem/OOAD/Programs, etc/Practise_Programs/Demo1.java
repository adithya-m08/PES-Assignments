class Box
{
double width;
double height;
double depth;

Box()
{
width=0;
height=0;
depth=0;
}

Box(double w,double h,double d)
{
width=w;
depth=d;
height=h;
}

Box(Box ob)// passing derived b--> Box ob=b;
{
width=ob.width;
height=ob.height;
depth=ob.depth;
//depth=ob.weight;
}

double volume()
{
return width*height*depth;
}
}

class Boxweight extends Box
{
double weight;

Boxweight()
{
super();
weight=0;
}

Boxweight(double w,double h, double d, double m)
{
super(w,h,d);//parm ctt
weight=m;
}

Boxweight(Boxweight b)
{
super(b);//BC copy ctt will be called
weight=b.weight;
}
}

class Demo1
{
public static void main(String args[])
{
Boxweight zobj=new Boxweight(); //int a;
System.out.println(zobj.volume());

 Boxweight pobj=new Boxweight(10,20,30,23);//int a=10
System.out.println(pobj.volume());

Boxweight oobj=new Boxweight(pobj); //int a=b;
System.out.println(oobj.volume());
}
}
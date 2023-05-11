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

public String toString(){
return width + " " + height + " " + depth;
}
}


public class p1_object{
public static void main(String[] args)
{
 Box obj = new Box();
System.out.println(obj);
Box new_obj = new Box(3,2,1);
System.out.println(new_obj);
}
}

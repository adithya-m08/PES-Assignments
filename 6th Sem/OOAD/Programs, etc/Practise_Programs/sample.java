class line extends point
{
point p1;
//point p2;
line(int x,int y,int a, int b)
{
p1=new point(x,y);
p2=new point(a,b);
}

void print()
{
//ystem.out.println("x= "+x, "y="+y+)
p1.disp();
p2.disp();
}
}

class point 
{
int x;
int y;
point(int x,int y)
{
this.x=x;
this.y=y;
}
void disp()
{
System.out.println("x= "+x+",y= "+y);
}
}


class sample
{
public static void main(String args[])
{
line l1=new line(10,20,30,40);
l1.print();
}
}
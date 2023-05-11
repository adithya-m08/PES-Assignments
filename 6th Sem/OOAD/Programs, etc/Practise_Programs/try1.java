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
System.out.println("x="+x+"y="+y);
}
}
class line
{
point p1;
point p2;

line(int x,int y,int a, int b)
{
p1=new point(x,y);
p2=new point(a,b);
}
void print()
{
System.out.println(p1.x+","+p1.y+","+p2.x+","+p2.y);
p1.disp();
p2.disp();
}

}
class try1
{
public static void main(String args[])
{
line l=new line(10,20,30,40);
l.print();
}
}
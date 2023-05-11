class test
{
static<T> void genericdisp(T ele, T a)
{
System.out.println(ele.getClass().getName());
System.out.println(ele);
System.out.println(a);
}

public static void main(String args[])
{
demo d=new demo();
genericdisp(23,87.4);//int and float
genericdisp(23,'a');
genericdisp("hello",100);
genericdisp(23,d);
}
}
class demo
{
int x;
public String toString()
{
return "val of x="+this.x;
}
}
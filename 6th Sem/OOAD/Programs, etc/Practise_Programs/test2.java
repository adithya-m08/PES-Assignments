class dim<T>
{
private T len;
private T br;
private T ht;

dim(T l,T b,T h)
{
len=l;
br=b;
ht=h;
}
void disp()
{
System.out.println(len);
System.out.println(br);
System.out.println(ht);
}
T getdim()
{
return len;
}
}
class test2
{
public static void main(String args[])
{
dim<Integer> t=new dim<Integer>(10,20,30);
t.disp();
t.getdim();
}
}

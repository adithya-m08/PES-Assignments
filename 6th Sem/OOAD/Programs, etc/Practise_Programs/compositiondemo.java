
class course
{
String crs1;
String crs2;
course(String crs1,String crs2)
{
this.crs1=crs1;
this.crs2=crs2;
}
void print()
{
System.out.println(crs1);
System.out.println(crs2);
}
}


class student
{
int srn;
String name;
course c1;
student(int srn, String name, course c1)
{
this.srn=srn;
this.name=name;
this.c1=c1;
}
void display()
{
System.out.println(srn);
System.out.println(name);
c1.print();
}
}

class compositiondemo
{
public static void main(String args[])
{
course c=new course("ooadj","cc");
student s1=new student(10,"pranitha",c);
s1.display();
}
}
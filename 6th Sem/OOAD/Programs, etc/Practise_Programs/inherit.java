class parentclass
{
protected int x;
int y;
int z;

void displayparent()
{
x++;
System.out.println("Parent class display");
}
}

class childclass extends parentclass
{
int a;
void displaychild()
{
x++;
System.out.println("Child class display");
}

}

class inherit
{
public static void main(String args[])
{

parentclass pobj=new parentclass();
childclass cobj=new childclass();

pobj.x=10;
pobj.y=20;
pobj.z=30;
pobj.displayparent();
//pobj.a=100;
//pobj.displaychild();

cobj.x=10;
cobj.y=20;
cobj.z=30;
cobj.a=100;

cobj.displaychild();
cobj.displayparent();
}
}



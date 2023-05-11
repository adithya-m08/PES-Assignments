class A{
	int a;
	void methodA()
	{
		System.out.println("methodA  "+a);
	}
	void methodC()
	{
		System.out.println("Class A's:methodC");
	}
}

class B extends A{
	void methodB(){
		System.out.println("methodB");
	}
	void methodC(){
		System.out.println("Class B's:methodC");
	}
}
class Inheritance_Demo{
	public static void main(String[]args){
		A o1 = new A();
		o1.a = 5;
		o1.methodA();
		o1.methodC();

		B o2 = new B();
		o2.a=10;
		o2.methodA();
		o2.methodB();
		o2.methodC();

		A o3 = new B();
		o3.methodA();
		//o3.methodB();  //Error: Variable o3 is of type A
		o3.methodC();
		//B o4 = new A();// Error: A cannot be converted into type B
	}
}




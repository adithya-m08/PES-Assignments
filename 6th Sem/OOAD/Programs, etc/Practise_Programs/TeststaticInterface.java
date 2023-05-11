// A simple Java program to TestClassnstrate static
// methods in java
interface TestInterface
{
	// abstract method
	public void square (int a);

	// static method
	static void show()
	{
		System.out.println("Static Method Executed");
	}
}

class TeststaticInterface implements TestInterface
{
	// Implementation of square abstract method
	public void square (int a)
	{
		System.out.println(a*a);
	}

	public static void main(String args[])
	{
		TestClass1 d = new TestClass1();
		d.square(4);

		// Static method executed
		TestInterface.show();
	}
}

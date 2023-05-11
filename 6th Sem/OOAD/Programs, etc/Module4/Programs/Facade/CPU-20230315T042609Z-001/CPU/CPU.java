class CPU
{
	public void freeze(){
		System.out.println("freezing");
	}
	public void jump(){
		System.out.println("jumping");
	}
	public void execute(){
		System.out.println("executing");
	}
}
class Memory
{
	void load()
	{
		System.out.println("loading");
	}
}
class Harddrive
{
	void read()
	{
		System.out.println("read");
	}

}

class ComputerFacade
{
		private CPU processor;
		private Memory ram;
		private Harddrive hd;
		ComputerFacade()
		{
			this.processor = new CPU();
			this.ram = new Memory();
			this.hd = new Harddrive();
		}
		void start()
		{
			processor.freeze();
			ram.load();
			processor.jump();
			processor.execute();
		}
}

//实现单例模式

public sealed class Singleton4
{
	private Singleton4()
	{
	}
    private static Singleton4 instance=new Singleton4();
	//上面的语句是调用静态构造函数，由于静态类存储的问题，他的实例只能被产生一次
	//所以没有了同步的问题
	public static Singleton4 Instance
	{
		get
		{
			return instance;
		}
	}
}
//缺点：只要调用了类Singleton4就会生成实例，可能会过早地创建实例，浪费内存



public sealed class Singleton5
{
	Singleton5()
	{
	}
	public static Singleton5 Instance
	{
		get
		{
			return Nested.instance;
		}
	}
	class Nested //私有的
	{
		static Nested()
		{
		}
		internal static readonly Singleton5 instance=new Singleton5();
	}
}
//只有调用Singleton5.Instance属性才会创建实例，可以实现按需创建
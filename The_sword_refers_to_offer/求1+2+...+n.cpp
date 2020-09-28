//方法一：构造函数
class Temp
{
public:
    Temp(){++N;Sum+=N;}//构造函数

    static void Reset(){N=0;Sum=0;}

    static unsigned int GetSum(){return Sum;}

private:   
    static unsigned int N;//static修饰之后这个变量放在元空间，不管使用这个类new出多少个对象，这些对象里的这个变量共用一个地址，即这些对象里的这个变量都是同一个
    static unsigned int Sum;//static修饰之后这个变量放在元空间，不管使用这个类new出多少个对象，这些对象里的这个变量共用一个地址，即这些对象里的这个变量都是同一个
};


//调用N次即可
unsigned int Temp::N=0;
unsigned int Temp::Sum=0;//声明并初始化
unsigned int Sum_Solution(unsigned int n)
{
    Temp::Reset();//调用方法 初始化N，Sum

    Temp *a=new Temp[n];//这是一个数组 相当于调用了n次构造函数即调用了n次Temp()
    delete []a;
    a=nullptr;

    return Temp::GetSum();
}


//方法二：虚函数
class A;
A* Array[2];

class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {//递归到底开始返回
        return 0;
    }
};

class B:public A
{
public:
    virtual unsigned int Sum(unsigned int n)//重写
    {
        return Array[!!n]->Sum(n-1) + n;//!!n的值是1，也就是说调用的还是classB 这样才能形成一个递归过程 当n=0时，相当于递归到底开始返回
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0]=&a;
    Array[1]=&b;//这里的赋值很重要

    int value = Array[1]->Sum(n);//第一次调用必须调用classB

    return value;
}


//方法三：函数指针
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n)
{//递归到底开始返回
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2]={Solution3_Teminator,Sum_Solution3};//函数数组，分别赋值数组中第0个元素和第一个元素
    return n+f[!!n](n-1);//!!n的值是1，也就是说调用的还是Sum_Solution3 这样才能形成一个递归过程 当n=0时，相当于递归到底开始返回
    }
}


//方法四：模版类型
template <unsigned int n>struct Sum_Solution4
{
    enum Value{N=Sum_Solution4<n-1>::N + n};//Sum_Solution4<n-1>::N引用静态类型中的变量即n-1 这里可以形成递归
};

template <>struct Sum_Solution4<1>
{//递归到底开始返回
    enum Value{N=1};
};




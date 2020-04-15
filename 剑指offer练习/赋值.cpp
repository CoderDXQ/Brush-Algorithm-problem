//以下是某个类型的声明，请为该类型添加赋值运算符函数
class CMyString
{
public:
   CMyString(char *pDta = nullptr);
   CMyString(const CMyString &str);
   ~CMyString(void);

private:
   char *m_pData;
}

//Solution1:
//重载 赋值为str
CMyString& CMyString::operator=(const CMyString &str)//传地址
{//const可以避免形参变为实参，这会调用一次复制构造函数造成无谓消耗
   if(this==&str)//地址相同，同一个实参直接返回，否则被初始化之后就不能赋值了
       return *this;

   delete []m_pData;
   m_pData=nullptr;//初始化，释放内存，防止内存泄漏

   m_pData=new char[strlen(str.m_pData)+1];//字符串最后有一个结束符
   strcpy(m_pData,str.m_pData);//复制字符串

   return  *this;//返回值
}
//缺点，如果new操作失败，那么m_pData的内容就损失了

//Solution2:
//重载
CMyString& CMyString::operator=(const CMyString &str)
{
   if (this!=&str)
   {
      CMyString strTemp(str);//创建临时实例，会新分配内存

      char* pTemp=strTemp.m_pData;//指针指向的地址互相交换
      strTemp.m_pData=m_pData;
      m_pData=pTemp;//m_pData是this里的成员
   }//运行完if语句会自动释放strTemp的内存 

   return *this;
}











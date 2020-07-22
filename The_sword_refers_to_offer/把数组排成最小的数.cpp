//这道题的核心就是排序规则及其实现
//考虑大数问题，直接使用字符串
//P229有自反性、对称性、传递性的证明以及反证法
#include<bits/stdc++.h>
using namespace std;

const int g_MaxNumberLength=10;

char* g_StrCombine1=new char[g_MaxNumberLength*2+1];
char* g_StrCombine2=new char[g_MaxNumberLength*2+1];

//字符串相关函数的使用
//
//这个函数必须在PrintMinNumber前面进行声明
int compare(const void* strNumber1,const void* strNumber2)
{//排序规则
    strcpy(g_StrCombine1,*(const char**)strNumber1);
    strcat(g_StrCombine1,*(const char**)strNumber2);

    strcpy(g_StrCombine2,*(const char**)strNumber2);
    strcat(g_StrCombine2,*(const char**)strNumber1);
  
    return strcmp(g_StrCombine1,g_StrCombine2);
}


void PrintMinNumber(int* numbers,int length)
{
    if(numbers == nullptr || length<=0)
        return;//健壮性
    
    char** strNumbers=(char**)(new int[length]);
    for(int i=0;i<length;i++)
    {//转化成字符串 如果在一开始就读入字符串就不用这么麻烦
        strNumbers[i]=new char[g_MaxNumberLength+1];
        sprintf(strNumbers[i],"%d",numbers[i]);//数字转字符串
    }

//库函数 快速排序 compare是排序规则
    qsort(strNumbers,length,sizeof(char*),compare);

    for(int i=0;i<length;i++)
        printf("%s",strNumbers[i]);
    printf("\n");

    for(int i=0;i<length;i++)
        delete[] strNumbers[i];
}



int main()
{
    int num[10000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    
    PrintMinNumber(num,n);

    return 0;
}

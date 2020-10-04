#include<stdio.h>
#include<iostream>


using namespace std;
int main()
{
    int n,a[101],sum=0;
    bool label[20001];

    memset(label,0,sizeof(label));
    memset(a,0,sizeof(a));

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],label[a[i]]=true;
    
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(label[a[i]+a[j]] && a[i]!=a[j]) sum++,label[a[i]+a[j]]=false;//这里有个坑 因为集合中的数是不同的  统计的是数的个数而不是次数 因此要注意集合中一个数被认定为是两个数的和之后要赋值为false

    cout<<sum<<endl;

    return 0;
}


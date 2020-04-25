//并查集原理实验

/*
#include<bits/stdc++.h>
using namespace std;

int father[100];

int find(int x)
{
    return father[x]==x ? x:father[x]=find(father[x]);
}

void shuchu()
{
    cout<<"*****************************************"<<endl;
    for(int i=1;i<=10;i++)
        cout<<father[i]<<' ';

    cout<<"father[0]="<<father[0]<<' '<<"father[11]="<<father[11]<<endl;
}
int main()
{
    for(int i=0;i<=11;i++)
        father[i]=i;
    shuchu();

    for(int i=1;i<=10;i++){
        int x=find(i);
        if(x<=5) father[x]=father[0];
        else father[x]=father[11];
        shuchu();
    }

    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
//并查集不是一个树形的结构 它是扁平的
void shuchu();

int father[100];
/*
int find(int x)
{
    shuchu();
    return father[x]==x ? x:father[x]=find(father[x]);
}*/

int find(int x)
{
    if(father[x]==x)
    {
        cout<<"x="<<x<<endl;
        shuchu();
        return x;
    }
    else
    {
        cout<<"x="<<x<<endl;
        shuchu();
        father[x]=find(father[x]);//在调用返回的过程中会使father数组的值变为各自下标自己的爹
        cout<<"x="<<x<<endl;
        shuchu();
        return father[x];//向上逐级返回自己的爹
    }
}

void shuchu()
{
   // cout<<"*****************************************"<<endl;
    for(int i=1;i<=10;i++)
        cout<<father[i]<<' ';

    cout<<"father[0]="<<father[0]<<' '<<"father[11]="<<father[11]<<endl;
}
int main()
{
    father[0]=0;
    for(int i=1;i<=11;i++)
        father[i]=i-1;
    shuchu();

    cout<<find(11)<<endl;
    cout<<"the elements in father are :"<<endl;
    shuchu();
    //最后一次输出father数组的结果全为0 
    //即father数组存的是各下标自己的爹
    //同一个并查集下所有的元素有相同的爹
    return 0;
}


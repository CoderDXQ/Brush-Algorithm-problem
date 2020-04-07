#include<bits/stdc++.h>
using namespace std;
int father[10005];
int find(int x)//找爹函数 
{//路径压缩 
	if (father[x]==x) return x;//返回条件
	else return father[x]=find(father[x]);//找最终的爹
}//利用递归一层一层的找爹 
int main()
{
	int n,m,z,x,y;
	cin>>n>>m;
    for(int i=1;i<=n;i++) father[i]=i;//初始化，设置自己的爹是自己 
	for(register int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
		{//将x，y所在的集合合并，就是把x，y的两个最终爹合并 
		    father[find(x)]=find(y);
		    //father[find(y)]=find(x);
	    }
		else
		{
			if(find(x)==find(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}	
	return 0;
}

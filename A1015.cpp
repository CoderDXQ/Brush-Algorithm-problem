#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool ss[100010];
int s;
void chuli(int t)
{
	for(int j=2;j<=sqrt(t);j++)
	{
		if(t%j==0) ss[t]=false;
		break;
	}
	int w=t+t;
	while(w<100010)
	{
		ss[w]=false;
	    w=w+t;
    }//注意语句之间的顺序 
}
void zhuanhuan(int n,int k)
{
    int b,a[50];
	s=0;b=0;
	while(n>0)
	{
		a[b]=n%k;
		n=n/k;
		b++;
	}//自动完成了翻转 
	for(int i=0;i<b;i++)
	{
		s=s*k+a[i];
	}
}
int main()
{
	int j,n,k,qq;
	int q[1000];
    fill(ss,ss+100010,true);
	fill(q,q+1000,-1);//必须用fill填充进行初始化 
	ss[0]=false;ss[1]=false;
	for(int i=2;i<100010;i++)
	{
		if(ss[i]==true)
		{
			chuli(i);
		}
	}
	scanf("%d",&j);
	qq=0;
    while(j>0)
    {
    	n=j;
    	scanf("%d",&j);
    	if(j>0)
		{
			k=j;
            if(ss[n]==false) 
			{
				q[qq]=0;
				qq++;
			}
			else
			{
				zhuanhuan(n,k);
				if(ss[s]==false)
				{
					q[qq]=0;
					qq++;
				}
				else
				{
					q[qq]=1;
					qq++;
				}
			}
			scanf("%d",&j);   
		}
		else
		{
			break;
		}
	}
	for(int i=0;i<qq;i++)
	{
		if(q[i]==0)
		{
			printf("No\n");
		}
		else
		{
	        printf("Yes\n");		
		}
	}
}


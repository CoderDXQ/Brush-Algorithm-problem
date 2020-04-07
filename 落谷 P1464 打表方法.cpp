#include<bits/stdc++.h>
using namespace std;
int sheet[30][30][30]={0};//初始化
int w(long long a,long long b,long long c) 
{
	if(a<=0||b<=0||c<=0)
	{
		return 1;
	}
	else if(a>20||b>20||c>20)
	{
		return w(20,20,20);
	}
	else 
	{
	if(sheet[a][b][c]==0)//表明还未存入数
	{
		if(a<b&&b<c)
		{
			sheet[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		}
		else
		{
			sheet[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
		}
	}
	return sheet[a][b][c];
    }
}
int main()
{
	long long a,b,c;
	w(21,21,21);
	while(1)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		
		if(a!=-1||b!=-1||c!=-1){ 
		if(a<=0||b<=0||c<=0)
	    {
		    printf("w(%lld, %lld, %lld) = 1\n",a,b,c);
		    continue;
	    }
	    if(a>20||b>20||c>20)
	    {
		    printf("w(%lld, %lld, %lld) = %d\n",a,b,c,sheet[20][20][20]);
		    continue;
	    }
	    	printf("w(%lld, %lld, %lld) = %d\n",a,b,c,sheet[a][b][c]);
	    }
		else
		{
			break;
		} 
	}
}

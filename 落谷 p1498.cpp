#include<bits/stdc++.h>
#define REP(I,start,end) for(int I=start;I<=end;I++)  
using namespace std;
int n;
char sav[2000][2000];
inline void DFS(int len,int x,int y,int base)//inline是内联，可以提高速度
{
    if(len==1)
    {
    	sav[x][y]='_';
    	sav[x][y+1]='_';
    	sav[x][y-1]='/';
    	sav[x][y+2]=' ';
    	sav[x-1][y]='/';
    	sav[x-1][y+1]=' ';
    	return;
	}
	int tmp=1<<len-1;
	DFS(len-1,x,base+y>>1,base);
	DFS(len-1,x,y+tmp,base+(tmp<<1));
	DFS(len-1,x-tmp,y,base+tmp);
}
int main()
{
	cin>>n;
	memset(sav,' ',sizeof(sav));
	int n1=1<<n;
	DFS(n,n1,n1,0);//递归分治 
	REP(i,1,n1)
	{
		REP(j,1,n1<<1)
		    putchar(sav[i][j]);
		putchar('\n');
	}
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
	int n,a[1030]={1};
int main()
{

	cin>>n;
	for(int i=0;i<1<<n;i++)//位运算 
	{
		for(int j=1;j<(1<<n)-i;j++) cout<<' ';//输出前面的空格
		for(int j=i;j>=0;j--) a[j]^=a[j-1];//按位异或运算，模仿杨辉三角规律 
        if(!(i%2))             //a[-1] =0;          
		    for(int j=0;j<=i;j++)
		        cout<<a[j];
		        //cout<<(a[j]?"/\\":"  ");//奇数行 
        else for(int j=0;j<=i;j+=2)
                cout<<a[j];
                //cout<<(a[j]?"/__\\":"    ");//偶数行 
        cout<<endl;
	}
	//cout<<a[-1]<<' '<<a[0];
	return 0;
}*/

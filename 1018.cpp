#include<stdio.h>
#include<string.h>//用cin必须有的头文件 
#include<iostream>
using namespace std;
int main()
{
	int i,n,k,aa,bb,j;
	char a,b;
	int js,jp,jf,ys,yp,yf;//SHENG PING FU
	int jj[3],yy[3];
	int pd[3][3]={{0,1,-1},{-1,0,1},{1,-1,0}};
	 js=0;jp=0;jf=0;ys=0;yp=0;yf=0;
	for(i=0;i<3;++i)
	{
	    jj[i]=0;yy[i]=0;
	}

	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
        if (a=='B') aa=0;if (a=='C') aa=1;if (a=='J') aa=2;
        if (b=='B') bb=0;if (b=='C') bb=1;if (b=='J') bb=2;
        if (pd[aa][bb]==0)  {jp++;yp++;}
        if (pd[aa][bb]==1)  {js++;yf++;jj[aa]++;}
        if (pd[aa][bb]==-1) {jf++;ys++;yy[bb]++;}
	}
	printf("%d %d %d\n",js,jp,jf);
	printf("%d %d %d\n",ys,yp,yf);
	k=-1;j=0;
	for(i=0;i<3;++i)
	{
		if(k<jj[i]) {k=jj[i];j=i;}
	}
	if (j==0) printf("B ");
	if (j==1) printf("C ");
	if (j==2) printf("J ");
	k=-1;j=0;
	for(i=0;i<3;++i)
	{
		if(k<yy[i]) {k=yy[i];j=i;}
	}
	if (j==0) printf("B\n");
	if (j==1) printf("C\n");
	if (j==2) printf("J\n");
}

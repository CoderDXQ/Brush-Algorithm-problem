#include<bits/stdc++.h>
using namespace std;
char a1[50001],b1[50001];
int a[50001],b[50001],i,x,len,j,c[50001];
int main()
{
	cin>>a1>>b1;
	a[0]=strlen(a1);b[0]=strlen(b1);
	for(i=1;i<=a[0];i++) a[i]=a1[a[0]-i]-48;//处理成倒序便于处理 
	for(i=1;i<=a[0];i++) b[i]=b1[b[0]-i]-48;
	for(i=1;i<=a[0];i++)
	    for(j=1;j<=b[0];j++)
	        c[i+j-1]+=a[i]*b[j];
    len=a[0]+b[0];
    for(i=1;i<len;i++)
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;c[i]%=10;
	    }
	while(c[len]==0&&len>1) len--;//处理多余的0和保护唯一的0
	for(i=len;i>=1;i--) cout<<c[i];
	cout<<endl;
	return 0; 
}

#include<stdio.h>
#include<algorithm>
using namespace std;
struct nn
{
	int add;
	int num;
}a[100005];
struct gg
{
//	int add;
	int num;
	int next;
}b[100005];
int cmp(nn a,nn b)//变量类型要注意 
{
	return a.num<b.num;
}

int main()
{
	bool bb[100005]={false};
	int i,j,n,ad,k,start,ne;
	scanf("%d %d",&n,&start);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&j);
	    scanf("%d %d",&k,&ne);
	    bb[j]=true;
		b[j].num=k;
		b[j].next=ne;	
	}
	i=0;j=start;
	while(j!=-1&&bb[j]==true)
	{
		a[i].num=b[j].num;
		a[i].add=j;
		i++;j=b[j].next;
	}
	n=i;
	
	if(n==0)printf("0 -1\n");
	//if(n==1)printf("%05d %d -1\n",a[0].add,a[0].num);
	if(n!=0){
	sort(a,a+n,cmp);
	printf("%d %d\n",n,a[0].add);
	for(i=0;i<n-1;i++)
	{
	    printf("%05d %d %05d\n",a[i].add,a[i].num,a[i+1].add);
	}
	printf("%05d %d -1\n",a[i].add,a[i].num);}

}

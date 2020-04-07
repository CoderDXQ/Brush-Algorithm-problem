#include<cstdio>
struct node
{
	char c;
	int next;
	bool flag;
}s[100010];
int main()
{
	int start1,start2;
	int i,j,n,k;
	char r;
	FILE *fp;
	fp=fopen("input.txt","r");
	if(fp==NULL) return 0;
	fscanf(fp,"%d %d %d",&start1,&start2,&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d %c %d",&j,&r,&k);
		s[j].next=k;
	}
	i=start1;
	 while(i!=-1)
	 {
          s[i].flag=true;	 //利用好标记的技巧来代替查找，题目默认不会出现中间存在相同部分的复杂情况 
		  i=s[i].next;
	 }
	for(j=start2;j!=-1;j=s[j].next)
	{
	    if (s[j].flag==true) break;	
	}
	if(j!=-1) printf("%05d\n",j);
	else
	printf("-1\n");
}

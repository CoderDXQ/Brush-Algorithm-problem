#include <stdio.h>
struct student{
	int hao,de,cai,lei,zong;	
}a[100001],b[100001];
void swit(student *a,student *b)
{
	student temp;
	temp=*a;*a=*b;*b=temp;
}

int main()
{
	student *p;
	int i,j,n,l,h,m,q,w,e,a1,a2,a3,a4;
	m=0;a1=0;a2=0;a3=0;a4=0;
	FILE *fp=fopen("input.txt","r");
	if (fp==NULL) return 0;
	fscanf(fp,"%d %d %d",&n,&l,&h);
	for(i=0;i<n;++i)
	{
		fscanf(fp,"%d %d %d",&q,&w,&e);
		if(w>=l&&e>=l)
		{
		a[m].hao=q;a[m].de=w;a[m].cai=e;a[m].zong=e+w;
		if (w>=h&&e>=h) {a1++;a[m].lei=1;++m;continue;}
		if (w>=h&&e<h)  {a2++;a[m].lei=2;++m;continue;}
		if (w<h&&e<h&&w>=e)   {a3++;a[m].lei=3;++m;continue;}
		a4++;a[m].lei=4;++m;
		}
		
	}

	printf("%d %d %d\n",n,l,h);
	
		for(i=0;i<m;++i)
	{
		printf("%d %d %d %d\n",a[i].hao,a[i].de,a[i].cai,a[i].lei);
		
	}
	printf("%d %d %d %d",a1,a2,a3,a4);

    swit(&a[1],&a[0]);////////////
    printf("%d %d %d\n",n,l,h);
	
		for(i=0;i<m;++i)
	{
		printf("%d %d %d %d\n",a[i].hao,a[i].de,a[i].cai,a[i].lei);
		
	}
	printf("%d %d %d %d",a1,a2,a3,a4);
}




#include<stdio.h>
#include<math.h>
int bb;
void  check(long s)
{
	int i,j,k,sqr;
	sqr=(int)sqrt(s);//注意强制类型转换的写法 
	int bz=0;

	for(i=2;i<=sqr;i++)//注意i=2行不行 
	{
		if(s%i==0)
		{
		bz=1;	
		break;
	    }
	}
	if(bz==0) bb=1;
}

int main()
{
	char shu[1005];
	int l,k,i,j,n;
	long s,ss;
	scanf("%d %d",&l,&k);
	for(i=0;i<=l;i++) scanf("%c",&shu[i]);
	s=0;ss=1;
	for(i=1;i<=k;i++)
	{
		s=s*10+shu[i]-'0';
		ss=ss*10;
	}
	j=i-1;
	ss=ss/10;
	bb=0;
	check(s);
	while(bb==0&&i<=l)
	{
		s=s%ss;
		n=shu[i]-'0';
		s=s*10+n;
		
	    check(s);
		j=i;
        if(bb==1) break;
		i++;
	}
	if(bb==0)
	{
	    printf("404\n");
    }
    else
    {
    	for(i=j-k+1;i<=j;i++) printf("%c",shu[i]);
    	printf("\n");	
	}
	return 0;
}

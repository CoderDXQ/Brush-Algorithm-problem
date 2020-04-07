#include <stdio.h>

struct student{
	int hao,de,cai,lei,zong;	
}a[100001],temp;

void quicksort(student a[],int left,int right);//函数声明要放在所有头文件、变量定义的后面 

void fuzhi(student *a,student *b)
{
*a=*b;
}
int Partition(student a[],int left,int right)
{
	int pd(student *a,student *b);////在函数中调用其他函数时，要在本函数中有声明； 
	//int k;
	//k=0;
	fuzhi(&temp,&a[left]);
	while(left<right)
	{
	//	k=pd(&a[right],&temp);
		while((left<right)&&(pd(&a[right],&temp)==0)) {right--;}/*&&(!(panduan(&a[right],&temp)))*/
		fuzhi(&a[left],&a[right]);
	//	k=pd(&a[left],&temp);
		while ((left<right)&&(pd(&a[left],&temp)==1)) {left++;}/*&&(panduan(&a[left],&temp))*/
		fuzhi(&a[right],&a[left]);
	}
	fuzhi(&a[left],&temp);
	return left;
}

void quicksort(student a[],int left,int right)
{
	if(left<right)
	{
		int pos=Partition(a,left,right);
		quicksort(a,left,pos-1);
		quicksort(a,pos+1,right);
	}
}

int pd(student *a,student *b)
{
	
	//printf("%d %d %d %d\n",(*a).hao,(*a).de,(*a).cai,(*a).lei);
//	printf("%d %d %d %d\n",(*b).hao,(*b).de,(*b).cai,(*b).lei);
	//printf("1\n");
	if((*a).lei<(*b).lei) {return 1;}
	else 
	{
	if ((*a).lei==(*b).lei)
	    {
	    	if((*a).zong>(*b).zong)	{return 1;}
	    	else{
	    		if((*a).zong==(*b).zong) 
				{
					if((*a).de>(*b).de)  {return 1;}
					else
					{
						if((*a).de==(*b).de)
						{
							if((*a).hao<(*b).hao) {return 1;}
							else {return 0;}
						}
						else {return 0;}
					}
				}
	    		else {return 0;}
			}
	    }
	else {return 0;}
    }
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
	//////////////////////////排序
	 
	quicksort(a,0,m-1);
	/////////////////////////
	printf("%d\n",m);
	for(i=0;i<m;++i)
	{
		printf("%d %d %d\n",a[i].hao,a[i].de,a[i].cai);
		
	}
//	printf("%d %d %d %d",a1,a2,a3,a4);
//	*p=a[1];a[1]=a[2];a[1]=*p;
// fuzhi(&a[1],&a[0]);


}




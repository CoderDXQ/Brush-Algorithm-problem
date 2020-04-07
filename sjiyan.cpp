#include<stdio.h>
#include<algorithm>
using namespace std;
struct student
{
	int hao,c,m,e,a,cx,mx,ex,ax,pro;
	char p;
};
bool cmpc(int q,int w)
{
	return st[q].c>st[w].c;
}
bool cmpm(int q,int w)
{
	return st[q].m>st[w].m;
}
bool cmpe(int q,int w)
{
	return st[q].e>st[w].e;
}
bool cmpa(int q,int w)
{
	return st[q].a>st[w].a;
}

int main()
{
    int a[2008];
    int i,n,t,k,j;
    bool bb=false;
    char cc;
    vector<student> st;
    scanf("%d %d",&n,&t);
    for(i=0;i<n;i++)
    {
    	scanf("%d %d %d %d",&st[i].hao,&st[i].c,&st[i].m,&st[i].e);
    	st[i].a=(st[i].hao+st[i].c+st[i].m+st[i].e)/3;
	}
	for(i=0;i<t;i++)
    {
    	scanf("%d",&a[i]);
		}	
	vector<student>::iterator it;
	sort(st.begin(),st.end(),cmpc);
	st[0].cx=1;
	for(i=1;i<n;i++)
    {
    	if(st[i].c==st[i-1].c) {st[i].cx==st[i-1].cx;}
    	else st[i].cx=i+1;
	}
	sort(0,n-1,cmpm);
	st[0].mx=1;
	for(i=1;i<n;i++)
    {
    	if(st[i].m==st[i-1].m) {st[i].mx==st[i-1].mx;}
    	else st[i].mx=i+1;
	}
	sort(0,n-1,cmpe);
	st[0].ex=1;
	for(i=1;i<n;i++)
    {
    	if(st[i].e==st[i-1].e) {st[i].ex=st[i-1].ex;}
    	else st[i].ex=i+1;
	}
	/*for(i=0;i<n;i++)
    {
    	printf("%d %d ",st[i].e,st[i].ex);
	}*/
	
	sort(st.begin(),st.end(),cmpa);
	st[0].ax=1;
	for(i=1;i<n;i++)
    {
    	if(st[i].a==st[i-1].a) {st[i].ax==st[i-1].ax;}//要注意数值相等时的序号相同问题 
    	else st[i].ax=i+1;
	}
	for(i=0;i<n;i++)
    {
    	k=3000;
    	if(k>st[i].ax) {k=st[i].ax;cc='A';}//单字符用单引号，多字符用双引号 
    	if(k>st[i].cx) {k=st[i].cx;cc='C';}
    	if(k>st[i].mx) {k=st[i].mx;cc='M';}
    	if(k>st[i].ex) {k=st[i].ex;cc='E';}
    	
    	st[i].pro=k;st[i].p=cc;
	}
	for(i=0;i<n;i++)
    {
    	if(st[i].ex==0) printf("%d\n",i);
	}
	
	for(i=0;i<t;i++)
    {
    	bb=false;
        for(j=0;j<n;j++)
		{
			if(st[j].hao==a[i]){
				printf("%d %c\n",st[j].pro,st[j].p);
				bb=true;
				break;
			}
			}	
		if(bb==false) printf("N/A\n");
	}	
}


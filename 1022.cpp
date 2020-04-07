#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int> st;
	long long a,b;
	int d,k;
	scanf("%lld %lld %d",&a,&b,&d);
    a=a+b;
    while(a>d)
    {
    	k=a%d;
    	a=a/d;
    	st.push(k);
	}
	if(a>0) st.push(a);
	
	while(st.empty()==false)
	{
		printf("%d",st.top());
		st.pop();
	}
	printf("\n");
}

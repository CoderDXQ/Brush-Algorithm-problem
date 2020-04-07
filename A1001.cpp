#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;
int main()
{
	int a,b,k,i,j;
	stack <int> st;
	scanf("%d %d",&a,&b);
	k=a+b;
	if (k==0) printf("0");
	else
	{
		if (k<0) printf("-");
		k=fabs(k);
	}
	a=0;
	while(k>0)
	{
		a++;
		j=k%10;
		k=k/10;
		st.push(j);
		if (a==3&&k>0){
			a=0;st.push(10);
		}		
	}

	while(st.empty()==false)
	{
		k=st.top();
		st.pop();
		if (k==10) printf(",");
		else
		  printf("%d",k);

	}
	printf("\n");
	
	//printf("%d\n",k);
	
	
	
	
}

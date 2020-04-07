#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c;
	int a11=0,b11=0,a21=0,b21=0;
	int A11[10000],A21[10000],B11[10000],B21[10000];
	int k11=0,k21=0;
	while(1)
	{
		cin>>c;
		if(c=='E') 
		{
			k11++;k21++;
			A11[k11]=a11;B11[k11]=b11;
			A21[k21]=a21;B21[k21]=b21;
			break;
		}
		else
		{
		    if(c=='W')
		    {
		    	a11++;a21++;
		    }	
		    else
		    {
		    	b11++;b21++;
		    }
		    if(((a11==11||b11==11)&&(abs(a11-b11)>=2)) || ((a11>11||b11>11)&&(abs(a11-b11)==2)))
			{
				k11++;
				A11[k11]=a11;B11[k11]=b11;
				a11=0;b11=0;
			}
		    if(((a21==21||b21==21)&&(abs(a21-b21)>=2)) || ((a21>21||b21>21)&&(abs(a21-b21)==2)))
		    {
		    	k21++;
		    	A21[k21]=a21;B21[k21]=b21;
		    	a21=0;b21=0;
			}	
		}
	}		
	for(int i=1;i<=k11;i++)
	{
		printf("%d:%d\n",A11[i],B11[i]);
	}
	cout<<endl;
	for(int i=1;i<=k21;i++)
	{
		printf("%d:%d\n",A21[i],B21[i]);
	}
 } 

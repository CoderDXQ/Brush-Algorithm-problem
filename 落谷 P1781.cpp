//�����ֵ�����ⲻ������������ʱ�ȽϺͼ�¼���� 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string st,last;
	int i,xh,n,wei=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>st;
		if(st.size()>wei)
		{
		    wei=st.size();
		    last=st;
		    xh=i;
	    }
		if(st.size()==wei&&st>last)
		{
			last=st;
			xh=i;
		}
		
	}
	cout<<xh<<endl;
	cout<<last<<endl;
 } 

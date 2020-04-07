#include<bits/stdc++.h>
using namespace std;
struct Match
{
	int start;
	int end;
}M[1000005];
bool cmp(Match a,Match b)
{
	return a.end<b.end;
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++) cin>>M[i].start>>M[i].end;
	sort(M,M+n,cmp);
	int pos=M[0].end;
	int ans=1;//第一个区间必须选 
	for(i=1;i<n;i++)
	{
		if(pos<=M[i].start)
		{
			pos=M[i].end;
			ans++;
		}
	}
	cout<<ans;
	return 0;
 } 

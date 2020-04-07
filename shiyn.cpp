#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int m,n,s;
	while(cin>>n>>m){
	
	    long k=1,kk=1; 
	    s=n+m;
	    if(m<n) swap(n,m);//默认n 是最小的
	
	    for(int i=1;i<=n;i++,s--) k*=s;
	    for(int i=2;i<=n;i++) kk*=i;
	    cout<<k/kk<<endl;
    }
	 
//	return k;
}
/*
#include<iostream>
using namespace std;
int ways(int m, int n);
int main()
{
 int m, n;//m为行数，n为列数
 int result;//走法个数
 while (cin >> m >> n)
 {
  result = ways(m, n);
  cout << result << endl;
 }
 system("pause");
 return 0;
}
int ways(int m, int n)
{
 int sum2 = 0;
 if (m == 1 && n == 1)
 {
  sum2 = 2;
 }
 else {
  int p = m + n;
  int sum = 1, sum1 = 1;
  int count = 0;
  //计算组合数上半部分
  for (int i = p; i >= p-m+1; i--)
  {
   sum *= i;
   ++count;
  }
  //组合数下半部分
  for (int j = count; j >= 1; j--)
  {
   sum1 *= j;
  }
  sum2 = sum / sum1;
 }
 return sum2;
}*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int m,n,s;
	while(cin>>n>>m){
	
	    long k=1,kk=1; 
	    s=n+m;
	    if(m<n) swap(n,m);//Ĭ��n ����С��
	
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
 int m, n;//mΪ������nΪ����
 int result;//�߷�����
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
  //����������ϰ벿��
  for (int i = p; i >= p-m+1; i--)
  {
   sum *= i;
   ++count;
  }
  //������°벿��
  for (int j = count; j >= 1; j--)
  {
   sum1 *= j;
  }
  sum2 = sum / sum1;
 }
 return sum2;
}*/

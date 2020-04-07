#include<bits/stdc++.h>
using namespace std;
map<string,int>q;

int main()
{
	string s;
	int k=0,j=0;
	int a[66];
    q["one"]=1;	q["two"]=2;q["three"]=3;q["four"]=4;q["five"]=5;q["six"]=6;q["seven"]=7;q["eight"]=8;q["nine"]=9;q["ten"]=10; 
    q["eleven"]=11;q["twelve"]=12;q["thirteen"]=13;q["fourteen"]=14;q["fifteen"]=15;q["sixteen"]=16;q["seventeen"]=17;q["eighteen"]=18;q["nineteen"]=19;q["twenty"]=20;
    q["a"]=1;q["both"]=2;q["another"]=1;q["first"]=1;q["second"]=2;q["third"]=3;
	for(int i=1;i<=6;i++){
		cin>>s;
		if(q[s]) {
	    k=q[s]*q[s]%100;
		if (k==0) continue;
		else a[++j]=k;//k如果小于10，存储时是一位数，但是按照题目要求应为两位数 
	}}
	sort(a+1,a+j+1);//sort函数默认从小到大排 
	cout<<a[1];
	for(int i=2;i<=j;i++)
	{
		if(a[i]<10)cout<<0;
		cout<<a[i];
	}
	//cout<<endl;
	return 0;
}

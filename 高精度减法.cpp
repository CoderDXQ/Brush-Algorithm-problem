#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;//�󳤶�Ҫ��a.length() b.length() 
	int aa[1000001]={0};
	int bb[1000001]={0};
	int cc[1000001]={0};
	int i,j,lena,lenb,lenc;
	cin>>a>>b;
	lena=a.length();lenb=b.length();
	//Ĭ��aa�Ǵ��� 
	memset(aa,0,sizeof(aa));memset(bb,0,sizeof(bb));memset(cc,0,sizeof(cc));
	if((lena<lenb)||(lena==lenb&&a<b)) {swap(a,b);swap(lena,lenb);cout<<'-';}
	//λ����Ȳ��ܱȽ��ֵ��� ,����֮��λ��ҲҪ���ű仯 
	for(i=0;i<lena;i++) aa[lena-i-1]=a[i]-48;//������е������Է����λ 
    for(i=0;i<lenb;i++) bb[lenb-i-1]=b[i]-48;
    lenc=max(lena,lenb);
	for(i=0;i<lenc;i++)	
	{
		if(aa[i]<bb[i]) {aa[i+1]--;cc[i]=aa[i]+10-bb[i];}
		else cc[i]=aa[i]-bb[i];
	}
	while(cc[lenc-1]==0&&lenc!=1) lenc--;
	for(i=lenc-1;i>=0;i--) cout<<cc[i];
	cout<<endl;
	return 0;
}

//��ռʽ���ȼ����̵��� 
#include<bits/stdc++.h>
using namespace std;
struct XY{int num,s,t,val;}v[1000000];
struct cmp{
	bool operator ()(XY &a,XY &b){//���������Ҫ�õ�ַ 
		return a.val<b.val||a.val==b.val&&a.num>b.num;
	}//����� 
}; 
int n=1,rest,cnt=1,sz=0,timee;
//cnt������һ����δ��ʼ�Ľ��� ,rest����δ������Ľ����� 
//sz�������ȶ����еĽ�������������Ϊ��ʱ time=v[cnt].s
priority_queue<XY,vector<XY>,cmp> Q;
int main()
{
	while(scanf("%d%d%d%d",&v[n].num,&v[n].s,&v[n].t,&v[n].val)!=EOF) n++;
	rest=n;v[n].s=1e9;
	while(rest){
		if(sz==0) Q.push(v[cnt]),timee=v[cnt].s,sz++,cnt++;//cpuΪ��ʱ�Ĵ���
		XY tmp=Q.top();Q.pop();sz--; 
		int last_time=timee;
		timee=min(v[cnt].s,tmp.t+last_time);
		if(timee==tmp.t+last_time) printf("%d %d\n",tmp.num,timee),rest--;
		    else tmp.t=tmp.t-(timee-last_time),Q.push(tmp),sz++,Q.push(v[cnt]),sz++,cnt++; 
	}
	return 0;
}

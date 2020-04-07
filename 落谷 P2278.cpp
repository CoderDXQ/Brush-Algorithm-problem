//抢占式优先级进程调度 
#include<bits/stdc++.h>
using namespace std;
struct XY{int num,s,t,val;}v[1000000];
struct cmp{
	bool operator ()(XY &a,XY &b){//对数组操作要用地址 
		return a.val<b.val||a.val==b.val&&a.num>b.num;
	}//大根堆 
}; 
int n=1,rest,cnt=1,sz=0,timee;
//cnt代表下一个还未开始的进程 ,rest代表未处理完的进程数 
//sz代表优先队列中的进程数，当对列为空时 time=v[cnt].s
priority_queue<XY,vector<XY>,cmp> Q;
int main()
{
	while(scanf("%d%d%d%d",&v[n].num,&v[n].s,&v[n].t,&v[n].val)!=EOF) n++;
	rest=n;v[n].s=1e9;
	while(rest){
		if(sz==0) Q.push(v[cnt]),timee=v[cnt].s,sz++,cnt++;//cpu为空时的处理
		XY tmp=Q.top();Q.pop();sz--; 
		int last_time=timee;
		timee=min(v[cnt].s,tmp.t+last_time);
		if(timee==tmp.t+last_time) printf("%d %d\n",tmp.num,timee),rest--;
		    else tmp.t=tmp.t-(timee-last_time),Q.push(tmp),sz++,Q.push(v[cnt]),sz++,cnt++; 
	}
	return 0;
}

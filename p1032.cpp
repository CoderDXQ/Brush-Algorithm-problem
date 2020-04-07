#include<bits/stdc++.h> 
using namespace std;
struct node{string str;int step;};//压入队列中的元素
string a,b;
string original[15],translated[15];
int n=0,ans=0;
map<string,int> mp;
 void bfs()
 {
 	queue<node>q;
 	q.push((node){a,0});
 	while(!q.empty())
 	{
 		node u=q.front();q.pop();
 		if(u.str==b) {ans=u.step;break;}//bfs首解最优 
 		if(mp[u.str]==1) continue;//重复，剪枝 
 		mp[u.str]=1;//标记 
		for(int j=0;j<n;j++){//枚举所有可能的变换原则
		    string st=u.str;int pos;//要用副本st来做 不然for循环会使step出错 
		    pos=st.find(original[j],0);
	        if(pos!=-1){
			    st=st.replace(pos,original[j].size(),translated[j]);
			    q.push((node){st,u.step+1});
			}
			else continue; 
		} 
	 }
 }
int main(){
	cin>>a>>b;
	while((cin>>original[n]>>translated[n])) n++;//蜜汁读取 
//	for(int i=0;i<=n;i++) cout<<original[i]<<"   "<<translated[i]<<endl;
	bfs();
	if(ans>10||ans==0) cout<<"NO ANSWER!"<<endl;
	else cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
struct node{string str;int step;};//ѹ������е�Ԫ��
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
 		if(u.str==b) {ans=u.step;break;}//bfs�׽����� 
 		if(mp[u.str]==1) continue;//�ظ�����֦ 
 		mp[u.str]=1;//��� 
		for(int j=0;j<n;j++){//ö�����п��ܵı任ԭ��
		    string st=u.str;int pos;//Ҫ�ø���st���� ��Ȼforѭ����ʹstep���� 
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
	while((cin>>original[n]>>translated[n])) n++;//��֭��ȡ 
//	for(int i=0;i<=n;i++) cout<<original[i]<<"   "<<translated[i]<<endl;
	bfs();
	if(ans>10||ans==0) cout<<"NO ANSWER!"<<endl;
	else cout<<ans<<endl;
	return 0;
}

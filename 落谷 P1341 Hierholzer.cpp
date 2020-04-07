/*#include<bits/stdc++.h>
using namespace std;
int a[106],c[10006],du[101],n,x,y,k,t,tot=0;
bool b[106][106];
char s[2];
void dfs(int u){
	for(int i=0;i<58;i++)
	if(b[u][i]){
		b[u][i]=b[i][u]=0;//删边 
		dfs(i);
	}
	c[++tot]=u;//递归退栈时存储，所以顺序是反的，也可以用栈 
}
int main(){
	cin>>n;
	k=0xfffffff;//重要赋值 
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s[0]-'A'; y=s[1]-'A';//节省空间 
		k=min(k,min(x,y));
		b[x][y]=b[y][x]=1;//无向图标记路径 
		du[x]++;du[y]++;//计算度 
	}
	for(int i=0;i<58;i++)
	    if(du[i]&1) a[++a[0]]=i;//计算度是奇数的点，并保存 
	if(a[0]==0) dfs(k);//题目要求输出字典序最小的方案 
//没有度为奇数的点 ，这是欧拉环路的情况 
	else if(a[0]==2) dfs(a[1]);//第一个度为奇数的点是端点 
//度为奇数的点为两个，这两个是两端的端点，这是欧拉路径的情况
    else{
	    cout<<"No Solution\n";
	    return 0;//必须有这个返回 
	}
	for(int i=tot;i>=1;i--) printf("%c",c[i]+'A');
	//for(int i=tot;i>=1;i--) cout<<c[i]+'A';
	//输出不规范，要用格式化输出
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int n,x,y,k,i,ss=0;
bool b[106][106];
char s[2];
int cnt[106]={0};
stack<int> c;
void dfs(int u){
	for(int i=0;i<58;i++)
	if(b[u][i]){
		b[u][i]=b[i][u]=0;//删边 
		dfs(i);
	}
	c.push(u);//递归退栈时存储，所以顺序是反的，也可以用栈 
}
int main(){
	cin>>n;k=0xfffffff;//重要赋值 
	vector<int> cnt(106,0);//变长数组的赋值 
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s[0]-'A'; y=s[1]-'A';//节省空间 
		k=min(k,min(x,y));
		b[x][y]=b[y][x]=1;//无向图标记路径 
	    cnt[x]^=1;cnt[y]^=1;
//利用异或运算，同0异1，运算偶数次是0，运算奇数次是1 
	}
	for(i=0;i<106;i++) if(cnt[i]) ss++; 
//要对所有的点进行遍历，ss是度为奇数的点的个数 
	if(ss&&ss!=2){
//条件取反：ss=0||s=2，即欧拉回路的情况和欧拉路径的情况 
	    cout<<"No Solution\n";
	    return 0;//必须有这个返回 
	}
	for(i=0;i<106;i++)if(cnt[i]) break; 
	if(i==106) dfs(k);
//没有度为奇数的点，及该情况是欧拉回路 ，k保证最小字典序 
	else dfs(i); //该情况是欧拉路径 ，也能保证最小字典序 
	while(!c.empty()){printf("%c",c.top()+'A');c.pop();}
	cout<<endl;
    return 0;
}


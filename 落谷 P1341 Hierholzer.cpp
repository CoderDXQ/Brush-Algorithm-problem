/*#include<bits/stdc++.h>
using namespace std;
int a[106],c[10006],du[101],n,x,y,k,t,tot=0;
bool b[106][106];
char s[2];
void dfs(int u){
	for(int i=0;i<58;i++)
	if(b[u][i]){
		b[u][i]=b[i][u]=0;//ɾ�� 
		dfs(i);
	}
	c[++tot]=u;//�ݹ���ջʱ�洢������˳���Ƿ��ģ�Ҳ������ջ 
}
int main(){
	cin>>n;
	k=0xfffffff;//��Ҫ��ֵ 
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s[0]-'A'; y=s[1]-'A';//��ʡ�ռ� 
		k=min(k,min(x,y));
		b[x][y]=b[y][x]=1;//����ͼ���·�� 
		du[x]++;du[y]++;//����� 
	}
	for(int i=0;i<58;i++)
	    if(du[i]&1) a[++a[0]]=i;//������������ĵ㣬������ 
	if(a[0]==0) dfs(k);//��ĿҪ������ֵ�����С�ķ��� 
//û�ж�Ϊ�����ĵ� ������ŷ����·����� 
	else if(a[0]==2) dfs(a[1]);//��һ����Ϊ�����ĵ��Ƕ˵� 
//��Ϊ�����ĵ�Ϊ�����������������˵Ķ˵㣬����ŷ��·�������
    else{
	    cout<<"No Solution\n";
	    return 0;//������������� 
	}
	for(int i=tot;i>=1;i--) printf("%c",c[i]+'A');
	//for(int i=tot;i>=1;i--) cout<<c[i]+'A';
	//������淶��Ҫ�ø�ʽ�����
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
		b[u][i]=b[i][u]=0;//ɾ�� 
		dfs(i);
	}
	c.push(u);//�ݹ���ջʱ�洢������˳���Ƿ��ģ�Ҳ������ջ 
}
int main(){
	cin>>n;k=0xfffffff;//��Ҫ��ֵ 
	vector<int> cnt(106,0);//�䳤����ĸ�ֵ 
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s[0]-'A'; y=s[1]-'A';//��ʡ�ռ� 
		k=min(k,min(x,y));
		b[x][y]=b[y][x]=1;//����ͼ���·�� 
	    cnt[x]^=1;cnt[y]^=1;
//����������㣬ͬ0��1������ż������0��������������1 
	}
	for(i=0;i<106;i++) if(cnt[i]) ss++; 
//Ҫ�����еĵ���б�����ss�Ƕ�Ϊ�����ĵ�ĸ��� 
	if(ss&&ss!=2){
//����ȡ����ss=0||s=2����ŷ����·�������ŷ��·������� 
	    cout<<"No Solution\n";
	    return 0;//������������� 
	}
	for(i=0;i<106;i++)if(cnt[i]) break; 
	if(i==106) dfs(k);
//û�ж�Ϊ�����ĵ㣬���������ŷ����· ��k��֤��С�ֵ��� 
	else dfs(i); //�������ŷ��·�� ��Ҳ�ܱ�֤��С�ֵ��� 
	while(!c.empty()){printf("%c",c.top()+'A');c.pop();}
	cout<<endl;
    return 0;
}


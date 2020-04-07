 #include<bits/stdc++.h>
 using namespace std;
 struct lol{
     int lc,rc,v;
} d[101000];
void dfs(int x)//中序遍历
{
	if(x==-1) return;//设置返回条件 
	dfs(d[x].lc);//左 
	if(d[x].v==0) printf("%d ",x);//根 
	dfs(d[x].rc);//右 
 } 
 int main()
 {
 	int n,m;
 	cin>>n;
 	d[1].v=0;d[1].lc=d[1].rc=-1;//初始化
	for(int i=2;i<=n;i++)//利用静态表建树 
	{
		int x,y;
		cin>>x>>y;
		d[i].lc=d[i].rc=-1;d[i].v=0;
		if(y==0)//插在左边 
        {
	    	if(d[x].lc!=0){//砍断左子树，插入节点 
	    		d[i].lc=d[x].lc;d[x].lc=i;
			}
			else d[x].lc=i;
		}	
		else{//砍断右子树，插入节点 
			if(d[x].rc!=0){
				d[i].rc=d[x].rc;d[x].rc=i;
			}
			else d[x].rc=i;
		}
	} 	
	cin>>m;
 	for(int i=1;i<=m;i++){
 	    int x;cin>>x;d[x].v=1;//结构体中的v标记是否删除节点	
		 }
	 dfs(1);//调用中序遍历输出 
 }

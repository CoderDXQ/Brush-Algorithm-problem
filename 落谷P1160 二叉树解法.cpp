 #include<bits/stdc++.h>
 using namespace std;
 struct lol{
     int lc,rc,v;
} d[101000];
void dfs(int x)//�������
{
	if(x==-1) return;//���÷������� 
	dfs(d[x].lc);//�� 
	if(d[x].v==0) printf("%d ",x);//�� 
	dfs(d[x].rc);//�� 
 } 
 int main()
 {
 	int n,m;
 	cin>>n;
 	d[1].v=0;d[1].lc=d[1].rc=-1;//��ʼ��
	for(int i=2;i<=n;i++)//���þ�̬���� 
	{
		int x,y;
		cin>>x>>y;
		d[i].lc=d[i].rc=-1;d[i].v=0;
		if(y==0)//������� 
        {
	    	if(d[x].lc!=0){//����������������ڵ� 
	    		d[i].lc=d[x].lc;d[x].lc=i;
			}
			else d[x].lc=i;
		}	
		else{//����������������ڵ� 
			if(d[x].rc!=0){
				d[i].rc=d[x].rc;d[x].rc=i;
			}
			else d[x].rc=i;
		}
	} 	
	cin>>m;
 	for(int i=1;i<=m;i++){
 	    int x;cin>>x;d[x].v=1;//�ṹ���е�v����Ƿ�ɾ���ڵ�	
		 }
	 dfs(1);//�������������� 
 }

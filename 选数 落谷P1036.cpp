#include<cstdio>
#include<cmath>
int ans=0,n,k,x,a[21],num=0;
bool prime(int q)
{
    int i;
	if(q==2) return true;
	for(i=2;i<=ceil(sqrt(q));i++)
	{
		if(q%i==0) return false;
		}	
	return true;
}
void dfs(int x,int y)
{
	int i,j;
	if(x>=k)//���µݹ�Ľ������� //">="����ط��Ƚ��� 
	{      //x���ڼ�����ѡ���ֵĸ��� 
		if(prime(num)) ans++;
		return;//���� 
	}
	for(i=y+1;i<=n;i++)
	{
		num+=a[i];
		dfs(x+1,i);//x������� 
		num-=a[i];//���� ���������ǵݹ�ͨ�ýṹ 
	 } 
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);//�˴�a[0]��������� 
	dfs(0,0);
	printf("%d",ans);
}

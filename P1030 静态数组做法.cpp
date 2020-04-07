#include <iostream>
#include <cstring>
using namespace std;
char s1[15],s2[15];
void dfs(int l1,int r1,int l2,int r2){
    if (l1>r1){
        return;
    }
    int p;
    for (int i=l1;i<=r1;++i){
        if (s1[i]==s2[r2]){
            p=i;
            break;
        }
    }
    cout<<s1[p];
    dfs(l1,p-1,l2,l2+p-1-l1);
    dfs(p+1,r1,r2-r1+p,r2-1);
}
int main() {
    int len;
    cin >> s1 >> s2;
    len = strlen(s1);
    dfs(0,len-1,0,len-1);
    return 0;
}

////////////////////
#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int dfs(int left1,int right1 ,int left2,int right2)//基本思路搜索后序遍历的根在中序遍历中的位置 
{
    int m=a.find(b[right2]);//输出根节点 
    cout<<b[right2];//注意m是int型的不能输出
    //输出应用后序遍历的根结点作为区间端点输出 
    if(m>left1)//确定查找区间
    {dfs(left1,m-1,left2,m-left1+left2-1);}//这个减一就是将right2转换到根节点的位置上 
    if(m<right1)
    {dfs(m+1,right1,m-left1+left2,right2-1);}//这个最让人费解的便是如何从中序遍历区间
    //查找到 后序遍历区间还是那句话------画一画 
}
int main()
{
    cin>>a>>b;
    dfs(0,a.size()-1,0,b.size()-1);//后序遍历用来确定根节点 
    return 0;
 } 

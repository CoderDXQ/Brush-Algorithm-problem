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
int dfs(int left1,int right1 ,int left2,int right2)//����˼·������������ĸ�����������е�λ�� 
{
    int m=a.find(b[right2]);//������ڵ� 
    cout<<b[right2];//ע��m��int�͵Ĳ������
    //���Ӧ�ú�������ĸ������Ϊ����˵���� 
    if(m>left1)//ȷ����������
    {dfs(left1,m-1,left2,m-left1+left2-1);}//�����һ���ǽ�right2ת�������ڵ��λ���� 
    if(m<right1)
    {dfs(m+1,right1,m-left1+left2,right2-1);}//��������˷ѽ�ı�����δ������������
    //���ҵ� ����������仹���Ǿ仰------��һ�� 
}
int main()
{
    cin>>a>>b;
    dfs(0,a.size()-1,0,b.size()-1);//�����������ȷ�����ڵ� 
    return 0;
 } 

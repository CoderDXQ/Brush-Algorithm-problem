/*#include<bits/stdc++.h>
using namespace std;
int n,x,y;
char a[2000][2000];
void copy(int &u,int &v)
{
	int i,j;
	for(i=1;i<=u;i++)
	    for(j=1;j<=v;j++)
	        a[i][v+j]=a[u+i][(v/2)+j]=a[i][j];
	u*=2;
	v*=2;
}
int main()
{
	memset(a,' ',sizeof(a));
	a[1][1]=a[2][2]='\\';//ת���ַ�
	a[1][2]=a[1][3]='_';
	a[1][4]=a[2][3]='/';
	x=2;y=4;
	cin>>n;
	for(int i=1;i<n;i++) copy(x,y);
	for(int i=x;i>0;i--){
		for(int j=y;j>0;j--) cout<<a[i][j];
		cout<<endl;
	} 
	return 0;
}*/
#include <iostream>
#include <string.h>
using namespace std;
int n,x,y;
char a[3000][3000];
void copy(int &u, int &v) {  //����ͼ�ڣ�����
    int i, j;
    for (i = 1; i <= u; i++)
        for (j = 1; j <= v; j++)
            a[i][v + j] = a[u + i][(v / 2) + j] = a[i][j];
    u *= 2;
    v *= 2;
}
int main(){
    memset(a, ' ', sizeof(a));
    a[1][1] = a[2][2] = '\\';
    a[1][2] = a[1][3] = '_';
    a[1][4] = a[2][3] = '/';   //��ʼ������ͼ��
    x = 2; y = 4;
    cin >> n;
    for (int i = 1; i < n; i++) copy(x, y);  //����n-1��
    for (int i = x; i > 0; i--) {
        for (int j = y; j > 0; j--) cout << a[i][j];//�������
        cout << endl;
    }
    return 0;
}

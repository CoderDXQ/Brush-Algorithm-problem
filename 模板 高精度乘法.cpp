#include<iostream>
#include<cstring>
using namespace std;
char a1[50001],b1[50001];
int a[50001],b[50001],i,x,len,j,c[50001];
int main ()
{
    cin >>a1 >>b1;//����������
    a[0]=strlen(a1);b[0]=strlen(b1);//���㳤��
    for (i=1;i<=a[0];++i)a[i]=a1[a[0]-i]-'0';//���ַ���ת��������
    for (i=1;i<=b[0];++i)b[i]=b1[b[0]-i]-'0';
    for (i=1;i<=a[0];++i)for (j=1;j<=b[0];++j)c[i+j-1]+=a[i]*b[j];//���˷�
    len=a[0]+b[0];                                       //ԭ����и߾���
    for (i=1;i<len;++i)if (c[i]>9){c[i+1]+=c[i]/10;c[i]%=10;}//��λ
    while (c[len]==0&&len>1)len--;//�ж�λ��
    for (i=len;i>=1;--i)cout <<c[i];//���
    return 0;
}

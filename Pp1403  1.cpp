#include<iostream>
using namespace std;
int n,ans;
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++)ans+=n/i;
    cout<<ans;
    return 0;
}
#include <cstdio>
int n,a[10000001],s;
void H(){//ɸ��������������͹���
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j+=i) s++;
    }
}
int main(){
    scanf ("%d",&n);
    H();
    printf ("%d",s);//���
    return 0;
}

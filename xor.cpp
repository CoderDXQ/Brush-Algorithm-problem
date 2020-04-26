#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int prefix[N],a[N];
vector<int> v[N];
int main(){
    int n;
    scanf("%d",&n);
    v[0].push_back(0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        prefix[i]=prefix[i-1]^a[i];
        v[prefix[i]].push_back(i);
    }
    int pos=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            pos=i;
            ans++;
        }
        else{
            int num=prefix[i];
            int idx=lower_bound(v[num].begin(),v[num].end(),i)-v[num].begin();
            printf("%d %d\n",idx,pos);
            if(idx>0&&v[num][idx-1]>=pos){
                pos=i;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num,sum=0,res=-9999;

    scanf("%d",&num);        
    sum+=num;
    res=max(res,sum);


    while(getchar()==' ')
    {
        scanf("%d",&num);        
        sum+=num;
        res=max(res,sum);
        if(sum<0) sum=0;
    }

    cout<<res<<endl;


    return 0;
}
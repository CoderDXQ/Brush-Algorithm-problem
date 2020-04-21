#include "stdio.h"
#include "limits.h"
#include <iostream>
using namespace std;
int main()
{
    int num;
    int ans = INT_MIN;
    int sum = 0;
    while(cin>>num)
    {
        sum += num;
        ans = max(ans, sum);
        if(sum<0)
            sum=0;
    }
    cout<<ans<<endl;
    return 0;
}

//https://www.nowcoder.com/questionTerminal/5a93963ecd2444a29c3e078e0a0c8796
#include "stdio.h"
#include "limits.h"
#include <iostream>
using namespace std;
int main()
{
    int num;
    int ans = INT_MIN;
    int sum = 0;
    
    scanf("%d",&num);
    sum += num;
        ans = max(ans, sum);
        if(sum<0)
            sum=0;
            
    while(getchar()==' ')
    {
    	scanf("%d",&num);
    	cout<<num<<endl;
        sum += num;
        ans = max(ans, sum);
        if(sum<0)
            sum=0;
    }

    cout<<ans<<endl;
    return 0;
}

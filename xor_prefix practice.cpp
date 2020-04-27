/*
#include<bits/stdc++.h>
using namespace std;

int prefix[1000005];//存前缀数组
int a[1000005];//存原数组
vector<int> v[1000005];//每个v[i]存储前缀值相同的元素下标位置

int main()
{
    int n;
    cin>>n;
    v[0].push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        prefix[i]=a[i]^prefix[i-1];
        v[prefix[i]].push_back(i);
    }

    int pos=0,ans=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            pos=i;
            ans++;
        }
        else
        {
            int idx=lower_bound(v[prefix[i]].begin(),v[prefix[i]].end(),i)-v[prefix[i]].begin();

            if(idx>0 && v[prefix[i]][idx-1]>=pos)
            {
                pos=i;
                ans++;
            }
        }
        
    }

    cout<<ans<<endl;
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxNonOverlapSeg(const int a[],int maxSeg[], int be, int n) //数组a
{
    if (be >= n)
        return 0; //剪枝
    if (maxSeg[be] > 0)//剪枝
        return maxSeg[be];

    int maxSegNum = 0, segNum = 0;
    int j, re_xor;
    for (int i = be; i < n; i++)
    {
        j = i;
        re_xor = a[j++];

        while (j < n && re_xor != 0)
            re_xor ^= a[j++]; //向后计算异或结果

        if (re_xor == 0)
        {
            segNum = 1 + findMaxNonOverlapSeg(a, maxSeg, j, n);
            maxSegNum = max(maxSegNum, segNum);
        }
    }

    maxSeg[be]=maxSegNum;//这句必须有 记忆化可以提高速度
    return maxSegNum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int maxSeg[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxSeg[i] = 0;
    }

    cout << findMaxNonOverlapSeg(a, maxSeg, 0, n) << endl;
    return 0;
}

/*
//将maxSeg数组写成静态全局变量,可以节省计算机资源
#include <bits/stdc++.h>
using namespace std;

static int maxSeg[100000];
int findMaxNonOverlapSeg(const int a[],int be, int n) //数组a
{
    if (be >= n)
        return 0; //剪枝
    if (maxSeg[be] > 0)
        return maxSeg[be];

    int maxSegNum = 0, segNum = 0;
    int j, re_xor;
    for (int i = be; i < n; i++)
    {
        j = i;
        re_xor = a[j++];

        while (j < n && re_xor != 0)
            re_xor ^= a[j++]; //向后计算异或结果

        if (re_xor == 0)
        {
            segNum = 1 + findMaxNonOverlapSeg(a, j, n);
            maxSegNum = max(maxSegNum, segNum);
        }
    }

    maxSeg[be]=maxSegNum;//这句必须有 记忆化可以提高速度
    return maxSegNum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxSeg[i] = 0;
    }

    cout << findMaxNonOverlapSeg(a, 0, n) << endl;
    return 0;
}
*/
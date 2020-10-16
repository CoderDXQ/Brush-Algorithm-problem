#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, m, x;
    int matrix[105][105];
    int record[105][105];
    char ch;
    memset(matrix, 0, sizeof(matrix)); 
    memset(record, 0, sizeof(record));
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin>>ch;
            if(ch=='*') record[i][j]=1;//如果在输入时发现是地雷 那么直接记录为1后在后续处理过程中直接八个方向加起来即可
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(record[i][j]!=1){
                matrix[i][j]=record[i-1][j]+record[i+1][j]+record[i][j-1]+record[i][j+1]+record[i-1][j-1]+record[i-1][j+1]+record[i+1][j+1]+record[i+1][j-1];
            }
        }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(record[i][j]==1)
            {
                cout<<"*";
            }
            else
            {
                cout<<matrix[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
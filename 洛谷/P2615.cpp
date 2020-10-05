// #include<stdio.h>
// #include<iostream>

// using namespace std;


// int main()
// {
//     int column[1600];//列
//     int row[1600];//行
//     int square[40][40];
//     int n;

//     memset(column,0,sizeof(column));
//     memset(row,0,sizeof(row));
//     memset(square,0,sizeof(square));

//     cin>>n;
//     column[1]=(n+1)/2;//可能需要类型转换
//     row[1]=1;
//     square[row[1]][column[1]]=1;

//     for(int i=2;i<=n*n;i++)
//     {
//         if(row[i-1]==1 && column[i-1]!=n)
//         {
//             row[i]=n;
//             column[i]=column[i-1]+1;
//             square[row[i]][column[i]]=i;

//         }
//         if(row[i-1]!=1 && column[i-1]==n)
//         {
//             row[i]=row[i-1]-1;
//             column[i]=1;
//             square[row[i]][column[i]]=i;
//         }
//         if(row[i-1]==1 && column[i-1]==n)
//         {
//             row[i]=row[i-1]+1;
//             column[i]=column[i-1];
//             square[row[i]][column[i]]=i;
//         }
//         if(row[i-1]!=1 && column[i-1]!=n)
//         {
//             if(square[row[i-1]-1][column[i-1]+1]==0)
//             {
//                 row[i]=row[i-1]-1;
//                 column[i]=column[i-1]+1;
//                 square[row[i]][column[i]]=i;
//             }
//             else
//             {
//                 row[i]=row[i-1]+1;
//                 column[i]=column[i-1];
//                 square[row[i]][column[i]]=i;
//             }
//         }
//     }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cout<<square[i][j];
//             if(j!=n) cout<<' ';
//         }
//         cout<<endl;
//     }
        
//     return 0;
// }

#include<iostream>
#include<stdio.h>

using namespace std;
int x,y,a[40][40],n;

int main()
{
    cin>>n;
    x=1,y=(n+1)/2;

    for(int i=1;i<=n*n;i++)
    {//这个幻方的规则就是如果右上为空就填上，否则就填在正下方 如果到头，按滚动的情况处理
        a[x][y]=i;
        if(!a[(x-2+n)%n+1][y%n+1]) x=(x-2+n)%n+1,y=y%n+1;//从第1行跳转到第n行的技巧  remember！！！
        else x=x%n+1;
    }

    for(int i=1;i<=n;i++)
    { 
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
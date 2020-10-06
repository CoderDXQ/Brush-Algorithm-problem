// #include<stdio.h>
// #include<iostream>
// #include<istream>

// using namespace std;

// int main()
// {
//     string st;
//     getline(cin,st);

//     int len,sum=0;
//     len=st.length();
//     for(int i=0;i<len;i++)
//     {
//         if(st[i]!=' ')
//             sum++;
//     }

//     cout<<sum<<endl;
//   //  cout<<st<<endl;



//     return 0;
// }

#include<stdio.h>
#include<iostream>
#include<istream>

using namespace std;

int main()
{
    string st;

    int len,sum=0;

    while(cin>>st)//在测试环境中可以 但是在本地不好测试
    {
        sum+=st.length();
    }
    cout<<sum<<endl;
  //  cout<<st<<endl;



    return 0;
}
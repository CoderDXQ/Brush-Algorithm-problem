#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define maxn 15
using namespace std;
struct node{//方便搜索，也可以使用pair简化
    string str;
    int step;
};
string a,b;
string orginal[maxn];
string translated[maxn];
int n,ans;
map<string,int> ma;//很重要的东西，用来判重，否则会TLE在第3点和第5点
string trans(const string &str,int i,int j){//借鉴了stdcall大爷的思想
    string ans = "";
    if (i+orginal[j].length() > str.length())
        return ans;

    for (int k=0; k < orginal[j].length();k++)
        if (str[i+k] != orginal[j][k])
            return ans;

    ans = str.substr(0,i);
    ans+=translated[j];
    ans+=str.substr(i+orginal[j].length());
    return ans;
}
void bfs(){//一个平淡无奇的bfs过程
    queue <node> q;node s;
    s.str = a;s.step = 0;
    q.push(s);
    while (!q.empty()){
        node u = q.front();q.pop();
        string temp;
        if(ma.count(u.str) == 1) //剪枝，判断重复的路径
            continue;
        if (u.str == b){ans = u.step;break; }
        ma[u.str] = 1;
        for (int i=0;i < u.str.length();i++)//枚举当前串所有可能位置
            for (int j=0; j<n; j++){//枚举所有可能手段
                temp = trans(u.str,i,j);
                if (temp != ""){
                    node v;
                    v.str = temp;
                    v.step = u.step+1;
                    q.push(v);
                }
            }
    }
    if (ans > 10 || ans == 0)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;

}
int main(){
    cin >> a >> b;
    while (cin >> orginal[n] >> translated[n]) n++;
    bfs();
    return 0;
}

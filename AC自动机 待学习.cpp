#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn =  2*1e6+9;

int trie[maxn][26]; //�ֵ���
int cntword[maxn];  //��¼�õ��ʳ��ִ���
int fail[maxn];     //ʧ��ʱ�Ļ���ָ��
int cnt = 0;

void insertWords(string s){
    int root = 0;
    for(int i=0;i<s.size();i++){
        int next = s[i] - 'a';
        if(!trie[root][next])
            trie[root][next] = ++cnt;
        root = trie[root][next];
    }
    cntword[root]++;      //��ǰ�ڵ㵥����+1
}
void getFail(){
    queue <int>q;
    for(int i=0;i<26;i++){      //���ڶ������г����˵���ĸ�ӽ�����
        if(trie[0][i]){
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }

//fail[now]    ->��ǰ�ڵ�now��ʧ��ָ��ָ��ĵط�
////tire[now][i] -> ��һ����ĸΪi+'a'�Ľڵ���±�Ϊtire[now][i]
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=0;i<26;i++){      //��ѯ26����ĸ
            if(trie[now][i]){
                //���������ӽڵ�Ϊ��ĸi+'a',��
//������ڵ��ʧ��ָ��ָ��(((�����׽ڵ�)��ʧ��ָ����ָ����Ǹ��ڵ�)����һ���ڵ�)
                //�е���,Ϊ�˷�����������������

                fail[trie[now][i]] = trie[fail[now]][i];
                q.push(trie[now][i]);
            }
            else//������õ�ǰ�ڵ������ӽڵ�
                //ָ��ǰ�ڵ�failָ�������ӽڵ�
                trie[now][i] = trie[fail[now]][i];
        }
    }
}


int query(string s){
    int now = 0,ans = 0;
    for(int i=0;i<s.size();i++){    //�����ı���
        now = trie[now][s[i]-'a'];  //��s[i]�㿪ʼѰ��
        for(int j=now;j && cntword[j]!=-1;j=fail[j]){
            //һֱ����Ѱ��,ֱ��ƥ��ʧ��(ʧ��ָ��ָ������ߵ�ǰ�ڵ����ҹ�).
            ans += cntword[j];
            cntword[j] = -1;    //����������Ľڵ���,��ֹ�ظ�����
        }
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s ;
        insertWords(s);
    }
    fail[0] = 0;
    getFail();
    cin >> s ;
    cout << query(s) << endl;
    return 0;
}




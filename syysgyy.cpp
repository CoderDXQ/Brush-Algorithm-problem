#include <bits/stdc++.h>
using namespace std;
string a,b;
string ra[7],rb[7];
struct node{
    string cur;//��ǰ�ַ���
    int cs;//��ǰ���޸Ĵ���
}q[2000000];
int main(){
    cin>>a>>b;
    int i=1;
    while(cin>>ra[i]>>rb[i]){i++;}
    i-=1;
    int head=0,tail=1;
    q[tail].cur=a;      //ԭ�ַ��������
    q[tail].cs=0;
    while(head<tail){
        head++;
        if(q[head].cs>10){//��������10����޽���������
            cout<<"NO ANSWER!"<<endl;
            return 0;
			}
        for(int j=1;j<=i;j++){
            int pos=q[head].cur.find(ra[j],0);
            while(1){//Ѱ�ҿ����޸ĵ��Ӵ�
                if(pos==-1){break;}//�Ҳ����˳�
                else{//�ҵ�֮����ַ����޸�֮���������У��ټ���������
                    tail++;
                    q[tail].cur=q[head].cur;
                    q[tail].cs=q[head].cs+1;
                    q[tail].cur.replace(pos,ra[j].size(),rb[j]);
                    if(q[tail].cur==b){
                        cout<<q[tail].cs;
                        return 0;
                    }
                    pos=q[head].cur.find(ra[j],pos+1);
                }
            }
        }
    }
    return 0; 
}

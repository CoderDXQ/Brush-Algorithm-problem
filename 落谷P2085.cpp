#include<bits/stdc++.h>
using namespace std;
int n,m;
struct func
{
    int a,b,c;
 } f[10004];
struct value
{
    int num,x,val;
}res[100004];//�Ƚϼ����� 
priority_queue<value,vector<value>,less<value> >q; 
//ֻ����less��������greater����һ���Ƕ�less�С�<"������ 
bool operator <(value a,value b) {return a.val>b.val;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&f[i].a ,&f[i].b ,&f[i].c );
        q.push((value){i,1,f[i].a +f[i].b +f[i].c});
    }
    for(int i=1;i<=m;i++){
        value t=q.top();
        q.pop();
        cout<<t.val <<" ";
        q.push((value){t.num ,t.x +1,f[t.num ].a *(t.x +1)*(t.x +1)+f[t.num ].b *(t.x +1)+f[t.num ].c } );
    }
    return 0;
}

#include<bits/stdc++.h>//�ṹ���ڲ� 
using namespace std;
int n,m;
struct func
{
    int a,b,c;
 } f[10004];
struct value
{
    int num,x,val;
    friend bool operator <(value a,value b){
    	return a.val>b.val;
	} 
}res[100004];
priority_queue<value>q; 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&f[i].a ,&f[i].b ,&f[i].c );
        q.push((value){i,1,f[i].a +f[i].b +f[i].c});
    }
    for(int i=1;i<=m;i++){
        value t=q.top();
        q.pop();
        cout<<t.val <<" ";
        q.push((value){t.num ,t.x +1,f[t.num ].a *(t.x +1)*(t.x +1)+f[t.num ].b *(t.x +1)+f[t.num ].c } );
    }
    return 0;
}

#include<bits/stdc++.h>//�ṹ���ⲿ 
using namespace std;
int n,m;
struct func
{
    int a,b,c;
 } f[10004];
struct value
{
    int num,x,val;
}res[100004];
struct cmp{
	bool operator()(value a,value b){
		return a.val>b.val;
	}
};
priority_queue<value,vector<value>,cmp>q; 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&f[i].a ,&f[i].b ,&f[i].c );
        q.push((value){i,1,f[i].a +f[i].b +f[i].c});
    }
    for(int i=1;i<=m;i++){
        value t=q.top();
        q.pop();
        cout<<t.val <<" ";
        q.push((value){t.num ,t.x +1,f[t.num ].a *(t.x +1)*(t.x +1)+f[t.num ].b *(t.x +1)+f[t.num ].c } );
    }
    return 0;
}

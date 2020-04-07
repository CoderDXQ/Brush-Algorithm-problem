#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 26
int n,equ,var,d[MAXN+10],x[MAXN+10];
typedef int matrix[MAXN+10][MAXN+10];
matrix a,g;
bool vis[MAXN+10];
char s[3][MAXN+10];
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
void read(){
    Read(n);
    scanf("%s%s%s",s[0],s[1],s[2]);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<2;j++)
            a[n-i][s[j][i]-'A'+1]++;
            a[n-i][s[2][i]-'A'+1]--;
    }
    for(i=1;i<=n;i++) g[i][i]=n,g[i][i-1]=-1;
    g[1][0]=0;
    equ=var=n;
}
int gcd(int a,int b){
    int t;
    while(b){t=a%b;a=b;b=t;}
    return a;
}
void gauss_jordan(){
    int i,j,row,col,mxr,lcm;
    for(row=col=1;row<=equ&&col<=var;row++,col++){
        mxr=row;
        for(i=row+1;i<=equ;i++) if(abs(a[i][col])>abs(a[mxr][col])) mxr=i;
        if(mxr!=row) swap(a[row],a[mxr]),swap(g[row],g[mxr]);
        if(!a[row][col]){row--;continue;}
        for(i=1;i<=equ;i++)
            if(i!=row&&a[i][col]){
                lcm=a[i][col]/gcd(a[i][col],a[row][col])*a[row][col];
                int t1=lcm/a[i][col],t2=lcm/a[row][col];
                for(j=1;j<=var;j++){
                    g[i][j]=t1*g[i][j]-t2*g[row][j];
                    a[i][j]=t1*a[i][j]-t2*a[row][j];
                }}}}
bool check(){
    int i,j;
    memset(vis,0,sizeof vis);
    for(i=1;i<=n;i++){
        x[i]=0;
        for(j=1;j<=n;j++) x[i]+=g[i][j]*d[j];
        if(x[i]%a[i][i]||x[i]/a[i][i]<0||x[i]/a[i][i]>=n||vis[x[i]/a[i][i]]) return 0;
        x[i]/=a[i][i];
        vis[x[i]]=1;
		}
	return 1;
}
void print(){
    for(int i=1;i<n;i++) printf("%d ",x[i]); 
	 printf("%d\n",x[n]);
}
void dfs(int i){
    if(i==n){
        if(check()){print(); exit(0);}
        return;}
    d[i]=1;dfs(i+1);
    d[i]=0;
    dfs(i+1);
}
int main(){read();gauss_jordan();dfs(1);}

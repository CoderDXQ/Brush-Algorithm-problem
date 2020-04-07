#include<stdio.h>
#include<math.h>
char A[1025];
void work(int low, int up)
{
    int mid = (low+up)/2;
    if (low!=up){
        work(low, mid);
        work(mid+1,up);
    }
    int i,a=0,b=0;
    for (i=low;i<=up;i++)
        if (A[i]=='0') a++;
        else b++;
    if (a&&b) printf("F");
    else if (a) printf("B");
    else printf("I");
}
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", A+1);
    work(1, pow(2,n));
    return 0;
}

#include <stdio.h>
int a;
void cmp()
{
    a=5;
}
int main()
{
	a=9;
	cmp();
	printf("%d",a);
}



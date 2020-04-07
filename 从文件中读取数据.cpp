#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char a[4][60];
	FILE *fp=fopen("input.txt","r");////////////////////////
	if(fp==NULL) {return 0;}////////////////////////////////
	for (i=0;i<4;++i) {fscanf(fp,"%s",a[i]);}///////////////
	for (i=0;i<4;++i) {printf("%s\n",a[i]);}
}

#include<bits/stdc++.h>
using namespace std;



int main()
{
	FILE *fp;
	//fp=fopen("input.txt","r");
	if((fp=fopen("input.txt","r"))==NULL) return 0;
	
	int n;
//	cin>>n;
	fscanf(fp,"%d",&n);
	
	printf("%d",n);
	
	fclose(fp);
	
	return 0;
}

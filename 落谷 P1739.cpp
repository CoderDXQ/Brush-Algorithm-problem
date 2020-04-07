#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,tot=0;
	while((c=getchar())!='@'){
		if(c=='(') tot++;
		else if(c==')') tot--;
		if(tot<0) {
		   cout<<"NO";
		   return 0;		
		}
	}
	if(tot==0) cout<<"YES";
	else cout<<"NO";//最后配对完之后仅剩一个"（" ,此时tot为 1 
    cout<<endl;
    return 0; 
}


#include<bits/stdc++.h>
using namespace std;
stack<char> zhan;
int main()
{
	char input;
	while(scanf("%c",&input)&&input!='@'){
		if(input=='(') zhan.push(input);
		if(input==')'){
			if(zhan.empty())
			{
				cout<<"NO"<<endl;
				return 0;//整个程序结束 
			}
			zhan.pop();
		}
	}
	if(zhan.empty()) printf("YES\n");
	else printf("NO\n");//最后配对完之后仅剩一个"（" 
	return 0;
}

























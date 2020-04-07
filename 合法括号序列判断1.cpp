#include<bits/stdc++.h>
using namespace std;
int main(){
	
        string A;
		int n;
        // write code here
        stack<char> st;
        for(int i=0;i<A.length();i++){
            if(A[i]!='(' &&  A[i]!=')') return false;
            else{
                if(A[i]=='(')st.push(A[i]);
                if(A[i]==')'){
                    if(st.empty()) return false;
                    else st.pop();
                }
            }
        }
        if(!st.empty()) return false;
        return true;
}


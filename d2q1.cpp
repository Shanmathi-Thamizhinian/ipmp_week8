#include <bits/stdc++.h>
using namespace std;

int prec(char ch){
	if(ch=='+'||ch=='-') return 1;
	else if(ch=='/'||ch=='*') return 2;
	else if(ch=='^') return 3;
	else return -1;
}

string infixToPostfix(string s){
	// Write your code here
	string res;
	stack<char> st;
	for(int i=0;i<s.length();i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) res+=s[i];
		else if(s[i]=='(') st.push(s[i]);
		else if(s[i]==')'){
			while(st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty()&&prec(s[i])<=prec(st.top())){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}

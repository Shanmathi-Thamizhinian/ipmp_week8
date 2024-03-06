#include <bits/stdc++.h>
using namespace std;

bool isOperator(char element) {
   switch (element) {
      case '+':
      case '-':
      case '/':
      case '*':
      return true;
   }
   return false;
}

string postfixToPrefix(string &s){
    // Write your code here.
    stack<string> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(isOperator(s[i])){
            string op1=st.top();   
            st.pop();
            string op2=st.top();   
            st.pop();
            string temp=s[i]+op2+op1;
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}

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

string postToInfix(string s) {
    // Write your code here.
   stack<string> st;
   int n=s.size();
   for(int i=0;i<n;i++){
    if(isOperator(s[i])){
      string op1=st.top();   
      st.pop();
      string op2=st.top();   
      st.pop();
      string temp="("+op2+s[i]+op1+")";
      st.push(temp);
    }
    else{
      st.push(string(1,s[i]));
    }
  }
  return st.top();
}

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
string prefixToInfixConversion(string &s){
	// Write your code here.
   stack<string> st;
   int n=s.size();
   for(int i=n-1;i>=0;i--){
    if(isOperator(s[i])){
      string op1=st.top();   
      st.pop();
      string op2=st.top();   
      st.pop();
      string temp="("+op1+s[i]+op2+")";
      st.push(temp);
    }
    else{
      st.push(string(1,s[i]));
    }
  }
  return st.top();
}

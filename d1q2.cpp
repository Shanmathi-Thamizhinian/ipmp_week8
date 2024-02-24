class MinStack {
public:
    stack<long long> st;
    long long minel=INT_MAX;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
            minel=val;
            st.push(val);
        }
        else if(val<minel){
            st.push(2*val-minel);
            minel=val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<minel){
            minel=2*minel-st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.top()<minel) return minel;
        return st.top(); 
    }
    
    int getMin() {
        return minel;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

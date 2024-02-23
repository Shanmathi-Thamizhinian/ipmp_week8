class MyQueue {
public:
    stack<int> inp,out;
    int temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            temp=out.top();
            out.pop();
            return temp;
        }
        else{
            int temp=out.top();
            out.pop();
            return temp;
        }
    }
    
    int peek() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            temp=out.top();
            return temp;
        }
        else{
            temp=out.top();
            return temp;
        }
    }
    
    bool empty() {
        return(inp.empty()&&out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

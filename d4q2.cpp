class StockSpanner {
public:
stack<int> st;
unordered_map<int,int> mpp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            mpp[price]=1;
            st.push(price);
            return 1;
        }
        else{
            int prize=0;
            while(!st.empty() && st.top()<=price){
                prize+=mpp[st.top()];
                mpp.erase(st.top());
                st.pop();
            }
            prize++;
            mpp[price]=prize;
            st.push(price);
            return mpp[price];
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

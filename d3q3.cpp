class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=INT_MIN;;
        int n=heights.size();
        stack<int> s;
        vector<int> l(n,0);
        vector<int> r(n,0);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) l[i]=0;
            else l[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) r[i]=n-1;
            else r[i]=s.top()-1;
            s.push(i);
        }
        for(int i=0;i<n;i++){
            area=max(area,(r[i]-l[i]+1)*heights[i]);
        }
        return area;
    }
};

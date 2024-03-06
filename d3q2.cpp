class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> ans;
        for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i%n]) s.pop();
        if(s.empty()){
            if(i<n) ans.push_back(-1);
            s.push(nums[i%n]);
        } 
        else{
            if(i<n) ans.push_back(s.top());
            s.push(nums[i%n]);
        }
     }
     reverse(ans.begin(),ans.end());
     return ans;
    }
};

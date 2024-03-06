class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mpp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                mpp[nums2[i]]=-1;
                s.push(nums2[i]);
            }
            else{
                while(!s.empty() && s.top()<nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    mpp[nums2[i]]=-1;
                    s.push(nums2[i]);
                }
                else{
                    mpp[nums2[i]]=s.top();
                    s.push(nums2[i]);
                }
            }
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};

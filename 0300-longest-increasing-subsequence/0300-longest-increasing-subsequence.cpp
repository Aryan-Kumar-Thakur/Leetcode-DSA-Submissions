class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ans.size()==0 || nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
};
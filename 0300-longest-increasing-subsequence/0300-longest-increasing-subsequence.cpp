class Solution {
    void solve(int ind,int n,vector<int>& nums,vector<int>& ans){
        if(ind==n){
            return;
        }
        if(ans.size()==0 || nums[ind]>ans.back()){
            ans.push_back(nums[ind]);
        }
        else{
            int idx=lower_bound(ans.begin(),ans.end(),nums[ind])-ans.begin();
            ans[idx]=nums[ind];
        }
        solve(ind+1,n,nums,ans);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        solve(0,n,nums,ans);
        return ans.size();
    }
};
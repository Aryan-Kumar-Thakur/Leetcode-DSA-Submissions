class Solution {
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int ind,int n){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind+1;i<n;i++){
            swap(nums[ind],nums[i]);
            solve(nums,ind+1,n);
            swap(nums[ind],nums[i]);
        }
        solve(nums,ind+1,n);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(nums,0,n);
        return ans;
    }
};
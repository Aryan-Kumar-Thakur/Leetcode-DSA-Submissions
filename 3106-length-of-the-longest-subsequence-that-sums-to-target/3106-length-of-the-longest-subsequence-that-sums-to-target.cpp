class Solution {
    int solve(vector<int>& nums, int target,int ind,int n,vector<vector<int>> &dp){
        if(target == 0){
            return 0;
        }
        if(target < 0 || ind >= n ){
            return INT_MIN;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int pick = 1+solve(nums,target-nums[ind],ind+1,n,dp);
        int notpick = 0+solve(nums,target,ind+1,n,dp);
        return dp[ind][target] = max(pick,notpick);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans = solve(nums,target,0,n,dp);
        return (ans > 0) ? ans : -1;
    }
};
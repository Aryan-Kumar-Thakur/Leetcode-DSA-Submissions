class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum & 1){
            return 0;
        }
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i]<=j){
                    dp[i][j]=(dp[i-1][j] || dp[i-1][j-nums[i]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};
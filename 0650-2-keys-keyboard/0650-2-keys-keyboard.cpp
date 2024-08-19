class Solution {
    int solve(int ind,int prevstep,int n,vector<vector<int>> &dp){
        if(ind==n){
            return 0;
        }
        if(ind>n){
            return INT_MAX/2;
        }
        if(dp[n][prevstep]!=-1){
            return dp[n][prevstep];
        }
        int a=1+solve(ind+prevstep,prevstep,n,dp);
        int b=2+solve(ind*2,ind,n,dp);
        return dp[ind][prevstep]=min(a,b);
    }
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(n/2+1,-1));
        return 1+solve(1,1,n,dp);
    }
};
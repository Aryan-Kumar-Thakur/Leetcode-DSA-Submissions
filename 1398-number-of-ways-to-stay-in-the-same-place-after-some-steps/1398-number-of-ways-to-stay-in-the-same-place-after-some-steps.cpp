class Solution {
    int mod=1e9+7;
    int solve(int ind,int steps,int arrlen,vector<vector<long long int>> &dp){
        if(ind >= arrlen || ind < 0){
            return 0;
        }
        if(ind > steps){
            return 0;
        }
        if(steps==0){
            return (ind==0);
        }
        if(dp[ind][steps]!=-1){
            return dp[ind][steps] % mod;
        }
        long long int r=solve(ind+1,steps-1,arrlen,dp) % mod;
        long long int l=solve(ind-1,steps-1,arrlen,dp) % mod;
        long long int s=solve(ind,steps-1,arrlen,dp) % mod;
        return dp[ind][steps] = (r % mod + l % mod + s % mod) %mod;
    }
public:
    int numWays(int steps, int arrLen) {
        int ind=0;
        vector<vector<long long int>> dp(steps+1,vector<long long int>(steps+1,-1));
        return (int)(solve(ind,steps,arrLen,dp) % mod);
    }
};
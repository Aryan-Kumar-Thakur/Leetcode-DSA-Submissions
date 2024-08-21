class Solution {
    int solve(int s,int e,string &str,vector<vector<int>> &dp){
        if(s>e){
            return 0;
        }
        if(s==e){
            return 1;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int ans=1+solve(s+1,e,str,dp);
        for(int i=s+1;i<=e;i++){
            if(str[i]==str[s]){
                ans=min(ans,solve(s,i-1,str,dp)+solve(i+1,e,str,dp));
            }
        }
        return dp[s][e]=ans;
    }
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};
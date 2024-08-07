class Solution {
    int solve(int st,int en,vector<int>& cuts,vector<vector<int>> &dp){
        if(st>en){
            return 0;
        }
        if(dp[st][en]!=-1){
            return dp[st][en];
        }
        int ans=INT_MAX;
        for(int i=st;i<=en;i++){
            int mini=cuts[en+1]-cuts[st-1]+solve(st,i-1,cuts,dp)+solve(i+1,en,cuts,dp);
            ans=min(ans,mini);
        }
        return dp[st][en]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int st=0,en=n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(1,m-2,cuts,dp);
    }
};
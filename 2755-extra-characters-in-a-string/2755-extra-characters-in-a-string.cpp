class Solution {
    int solve(int ind,int n,string s,set<string> &st,vector<int> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MAX;
        for(int i=ind;i<n;i++){
            string k=s.substr(ind,i-ind+1);
            if(st.find(k)!=st.end()){
                ans=min(ans,solve(i+1,n,s,st,dp));
            }
            ans=min(ans,1+solve(ind+1,n,s,st,dp));
        }
        return dp[ind]=ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(n,-1);
        return solve(0,n,s,st,dp);
    }
};
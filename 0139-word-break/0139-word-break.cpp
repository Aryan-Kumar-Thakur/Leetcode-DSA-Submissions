class Solution {
    // bool solve(int ind,set<string> &st,string &s,int n,vector<int> &dp){
    //     if(ind==n){
    //         return true;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     bool ans=false;
    //     for(int i=ind;i<n;i++){
    //         string k=s.substr(ind,i-ind+1);
    //         if(st.find(k)!=st.end()){
    //             ans=ans||solve(i+1,st,s,n,dp);
    //         }
    //     }
    //     return dp[ind]=ans;
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        // return solve(0,st,s,n,dp);
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            bool ans=false;
            for(int j=i;j<n;j++){
                string k=s.substr(i,j-i+1);
                if(st.find(k)!=st.end()){
                    ans=ans || dp[j+1];
                }
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
class Solution {
    int solve(int k,int n,vector<vector<int>> &dp){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int ans=INT_MAX;
        int lo=0,hi=n,temp=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int left=solve(k-1,mid-1,dp);
            int right=solve(k,n-mid,dp);
            temp=1+max(left,right);
            if(left<right){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};
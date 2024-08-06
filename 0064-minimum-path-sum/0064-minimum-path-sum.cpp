class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        prev[0]=grid[0][0];
        for(int i=1;i<m;i++){
            prev[i]=grid[0][i]+prev[i-1];
        }
        for(int i=1;i<n;i++){
            curr[0]=prev[0]+grid[i][0];
            for(int j=1;j<m;j++){
                curr[j]=grid[i][j]+min(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return prev[m-1];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        vector<int> prev(amount+1,1e8);
        vector<int> curr(amount+1,1e8);
        for(int i=0;i<=amount;i++){
            if(i % coins[0]==0){
                prev[i]=i/coins[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int pick=1e8,notpick=1e8;
                if(j>=coins[i]){
                    pick=1+curr[j-coins[i]];
                }
                notpick=prev[j];
                curr[j]=min(pick,notpick);
            }
            prev=curr;
        }
        if(prev[amount]>=1e8){
            return -1;
        }
        return prev[amount];
    }
};
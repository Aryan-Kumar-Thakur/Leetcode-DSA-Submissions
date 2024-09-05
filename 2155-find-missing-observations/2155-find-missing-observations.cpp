class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=0;
        for(auto it:rolls){
            sum+=it;
        }
        int tsum=(n+m)*mean;
        int remsum=tsum-sum;
        int x=remsum/n;
        int mod=remsum%n;
        if(x<=0 || x>6){
            return {};
        }
        vector<int> ans(n,x);
        int i=0;
        while(i<n && mod>0){
            ans[i]++;
            if(ans[i]<=0 || ans[i]>6){
                return {};
            }
            i++;
            mod--;
        }
        return ans;
    }
};
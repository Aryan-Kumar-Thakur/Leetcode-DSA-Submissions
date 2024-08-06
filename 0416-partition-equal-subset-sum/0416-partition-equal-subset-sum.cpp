class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum & 1){
            return 0;
        }
        int target=sum/2;
        // vector<vector<int>> dp(n,vector<int>(target+1,0));
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0]=1;
        if(nums[0]<=target){
            prev[nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            curr[0]=1;
            for(int j=1;j<=target;j++){
                if(nums[i]<=j){
                    curr[j]=(prev[j] || prev[j-nums[i]]);
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[target];
    }
};
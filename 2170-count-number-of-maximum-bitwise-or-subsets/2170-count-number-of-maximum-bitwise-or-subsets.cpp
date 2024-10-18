class Solution {
    int solve(int ind,int ans,int n,int maxi,vector<int>& nums){
        if(ind>=n){
            return (ans==maxi);
        }
        int x=solve(ind+1,ans,n,maxi,nums);
        int y=solve(ind+1,ans|nums[ind],n,maxi,nums);
        return (x+y);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        for(auto it:nums){
            maxi|=it;
        }
        int n=nums.size();
        int ans=solve(0,0,n,maxi,nums);
        return ans;
    }
};
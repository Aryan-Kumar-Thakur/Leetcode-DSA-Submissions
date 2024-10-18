class Solution {
    void solve(int ind,int ans,int &cnt,int n,int maxi,vector<int>& nums){
        if(ans==maxi){
            cnt++;
        }
        for(int i=ind;i<n;i++){
            solve(i+1,(ans|nums[i]),cnt,n,maxi,nums);
        }
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        for(auto it:nums){
            maxi|=it;
        }
        int n=nums.size();
        solve(0,0,cnt,n,maxi,nums);
        return cnt;
    }
};
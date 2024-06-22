class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        int ans=0,ocnt=0;
        pre[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                ocnt++;
            }
            if(ocnt-k >= 0){
                ans+=pre[ocnt-k];
            }
            pre[ocnt]++;
        }
        return ans;
    }
};
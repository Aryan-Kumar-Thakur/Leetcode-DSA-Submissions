class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(auto it:nums){
            maxi=max(it,maxi);
        }
        int ans=0,cnt=0;
        for(auto it:nums){
            if(it==maxi){
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};
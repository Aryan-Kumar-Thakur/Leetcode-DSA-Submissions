class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k,r=k;
        int n=nums.size();
        int mini=nums[k],ans=nums[k];

        while(l>0 || r<n-1){
            int left = (l > 0) ? nums[l-1]:0; 
            int right = (r < n-1) ? nums[r+1]:0;
            if(left > right){
                l--;
                mini=min(mini,left);
            }
            else{
                r++;
                mini=min(mini,right);
            }
            ans=max(ans,mini*(r-l+1));
        }
        return ans;
    }
};
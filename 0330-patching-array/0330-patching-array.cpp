class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m=nums.size();
        long long ans=0;
        long long i=0;
        int ind=0;
        while(i<n){
            if(ind < m && nums[ind]<=i+1){
                i+=nums[ind];
                ind++;
            }
            else{
                i=i*2+1;
                ans++;
            }
        }
        return ans;
    }
};
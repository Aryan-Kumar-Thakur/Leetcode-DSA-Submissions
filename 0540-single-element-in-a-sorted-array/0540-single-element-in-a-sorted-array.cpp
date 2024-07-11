class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mid % 2 ==1){
                mid--;
            }
            if(nums[mid]!=nums[mid+1]){
                hi=mid;
            }
            else{
                lo=mid+2;
            }
        }
        return nums[lo];
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            // cout<<mid<<endl;
            if((mid>0 && nums[mid]!=nums[mid-1]) && (mid<n-1 && nums[mid]!=nums[mid+1])){
                return nums[mid];
            }
            else if(mid==0 && nums[mid]!=nums[mid+1]){
                return nums[0];
            }
            else if(mid==n-1 && nums[n-1]!=nums[n-2]){
                return nums[n-1];
            }
            else if(mid>0 && nums[mid]==nums[mid-1]){
                if((mid-1) & 1){
                    hi=mid-2;
                }
                else{
                    lo=mid+1;
                }
            }
            else if(mid<n-1 && nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    lo=mid+2;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
    }
};
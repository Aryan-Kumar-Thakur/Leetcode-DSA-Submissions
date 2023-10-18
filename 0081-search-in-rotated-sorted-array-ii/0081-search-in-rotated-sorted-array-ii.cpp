class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n=arr.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]==arr[lo] && arr[mid]==arr[hi]){
                lo++;
                hi--;
            }
            else if(arr[lo]<=arr[mid]){
                if(arr[lo] <= target && arr[mid] > target){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else{
                if(arr[mid] < target && arr[hi] >=target){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return false;
    }
};
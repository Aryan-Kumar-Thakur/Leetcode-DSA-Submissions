#define PII pair<int,pair<int,int>>
class Solution {
    int find(vector<int> &nums,int mid,int n){
        int i=0,j=1;
        int cnt=0;
        while(j<n){
            while(nums[j]-nums[i] > mid){
                i++;
            }
            cnt+=(j-i);
            j++;
        }
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums[n-1]-nums[0];
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int cnt=find(nums,mid,n);
            if(cnt<k){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return hi;
    }
};
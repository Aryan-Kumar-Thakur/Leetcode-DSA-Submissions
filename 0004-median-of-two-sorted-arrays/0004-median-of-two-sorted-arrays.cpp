class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int mid=(n+m+1)/2;
        int lo=0,hi=n;
        while(lo<=hi){
            int px=(lo+hi)/2;
            int py=mid-px;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(px-1>=0){
                l1=nums1[px-1];
            }
            if(px < n){
                r1=nums1[px];
            }
            if(py-1>=0){
                l2=nums2[py-1];
            }
            if(py < m){
                r2=nums2[py];
            }
            if(l1<=r2 && l2<=r1){
                if((m+n) & 1){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1 > r2){
                hi=px-1;
            }
            else{
                lo=px+1;
            }
        }
        return -1;
    }
};
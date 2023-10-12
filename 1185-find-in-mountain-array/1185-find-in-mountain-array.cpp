/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int findmount(MountainArray &mountainArr){
        int i=1,j=mountainArr.length()-2;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            int x=mountainArr.get(mid-1);
            int y=mountainArr.get(mid);
            int z=mountainArr.get(mid+1);
            if(x < y  && y < z){
                i=mid+1;
            }
            else if(x > y && y > z){
                j=mid-1;
            }
            else if(x < y && y > z){
                return mid;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int x=findmount(mountainArr);
        int ans=INT_MAX;
        int i=0,j=x;
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=mountainArr.get(mid);
            if(x < target){
                i=mid+1;
            }
            else if(x > target){
                j=mid-1;
            }
            else{
                ans=min(ans,mid);
                j=mid-1;
            }
        }
        i=x+1,j=mountainArr.length()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=mountainArr.get(mid);
            if(x < target){
                j=mid-1;
            }
            else if(x > target){
                i=mid+1;
            }
            else{
                ans=min(ans,mid);
                j=mid-1;
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int maxleft=height[0];
        int maxright=height[n-1];
        int left=0,right=n-1;
        int ans=0;
        while(left<=right){
            if(height[left] >= maxleft){
                maxleft=height[left];
                left++;
            }
            else if(height[right] >= maxright){
                maxright=height[right];
                right--;
            }
            else if(height[left] < maxleft && maxleft <= maxright){
                ans+=maxleft-height[left];
                left++;
            }
            else{
                ans+=maxright-height[right];
                right--;
            }
        }
        return ans;
    }
};
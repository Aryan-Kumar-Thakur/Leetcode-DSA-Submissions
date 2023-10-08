class Solution {
    int solve(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int op1=INT_MIN,op2=INT_MIN;
        op1 = nums1[ind1] * nums2[ind2]  + solve(ind1-1,ind2-1,nums1,nums2,dp);
        op2 = max(solve(ind1-1,ind2,nums1,nums2,dp),solve(ind1,ind2-1,nums1,nums2,dp));
        return dp[ind1][ind2] = max(op1,op2);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
         int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
          for (int num : nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        for (int num : nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        if ((firstMax < 0 && secondMin > 0) || (firstMin > 0 && secondMax < 0)) {
            return max(firstMax * secondMin, firstMin * secondMax);
        }

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,nums1,nums2,dp);
    }
};
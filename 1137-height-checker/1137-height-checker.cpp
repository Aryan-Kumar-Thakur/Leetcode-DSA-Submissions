class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp(heights);
        sort(heights.begin(),heights.end());
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=temp[i]){
                ans++;
            }
        }
        return ans;
    }
};
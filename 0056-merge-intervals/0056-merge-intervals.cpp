class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> ans=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans[1]){
                ans[0]=min(ans[0],intervals[i][0]);
                ans[1]=max(ans[1],intervals[i][1]);
            }
            else{
                res.push_back(ans);
                ans=intervals[i];
            }
        }
        res.push_back(ans);
        return res;
    }
};
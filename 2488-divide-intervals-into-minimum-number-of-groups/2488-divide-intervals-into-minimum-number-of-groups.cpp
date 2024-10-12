class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=0;
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            while(!pq.empty() && intervals[i][0]>pq.top()){
                pq.pop();
            }
            pq.push(intervals[i][1]);
            int sz=pq.size();
            ans=max(ans,sz);
        }
        return ans;
    }
};
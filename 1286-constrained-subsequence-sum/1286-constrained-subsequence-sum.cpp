class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        int n=nums.size();
        int res=nums[0];
        for(int i=1;i<n;i++){
            while((i - pq.top().second) > k && !pq.empty()){
                pq.pop();
            }
            int curr=max(0,pq.top().first)+nums[i];
            res=max(res,curr);
            pq.push({curr,i});
        }
        return res;
    }
};
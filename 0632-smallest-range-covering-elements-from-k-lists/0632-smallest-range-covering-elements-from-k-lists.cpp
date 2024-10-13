class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n=nums.size();
        int maxi=INT_MIN;
        int ans=INT_MAX;
        vector<int> res;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],0,i});
            maxi=max(maxi,nums[i][0]);
        }
        while(!pq.empty()){
            int mini=pq.top()[0];
            int ind=pq.top()[1];
            int arr=pq.top()[2];
            pq.pop();
            if(maxi-mini < ans){
                ans=maxi-mini;
                res={mini,maxi};
            }
            if(ind<nums[arr].size()-1){
                pq.push({nums[arr][ind+1],ind+1,arr});
                maxi=max(maxi,nums[arr][ind+1]);
            }
            else{
                break;
            }
        }
        return res;
    }
};
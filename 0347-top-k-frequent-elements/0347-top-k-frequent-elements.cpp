#define PI pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<PI,vector<PI>,greater<PI>> pq;
        for(auto it:mp){
            if(pq.size()<k){
                pq.push({it.second,it.first});
            }
            else{
                if(pq.top().first < it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
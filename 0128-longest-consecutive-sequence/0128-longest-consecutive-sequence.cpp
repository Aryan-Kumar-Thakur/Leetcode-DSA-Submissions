class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]=1;
        }
        for(auto it:mp){
            mp[it.first]=mp[it.first]+mp[it.first-1];
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};
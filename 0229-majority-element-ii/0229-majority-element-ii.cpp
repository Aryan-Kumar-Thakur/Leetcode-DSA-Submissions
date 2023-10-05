class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        map<int,int> mp;
        int x=n/3;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second > x){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
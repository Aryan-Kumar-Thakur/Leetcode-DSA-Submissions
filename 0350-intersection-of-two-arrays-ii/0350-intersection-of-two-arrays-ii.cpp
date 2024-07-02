class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums1.size();
        map<int,int> mp;
        for(auto it:nums1){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:nums2){
            if(mp[it]>0){
                ans.push_back(it);
                mp[it]--;
            }
        }
        return ans;
    }
};
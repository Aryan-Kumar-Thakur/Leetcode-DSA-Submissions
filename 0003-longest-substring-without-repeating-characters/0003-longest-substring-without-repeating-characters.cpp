class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        int l=0,r=0;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            while(l<r && mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
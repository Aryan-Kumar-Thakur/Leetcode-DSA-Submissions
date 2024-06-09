class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans=0;
        mp[0]=1;
        int sum=0;
        for(auto it:nums){
            sum+=it;
            int x=sum%k;
            if(x<0){
                x+=k;
            }
            if(mp.find(x)!=mp.end()){
                ans+=mp[x];
            }
            mp[x]++;
        }
        return ans;
    }
};
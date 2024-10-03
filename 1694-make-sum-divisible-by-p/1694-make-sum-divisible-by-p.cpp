class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int rem=sum%p;
        if(rem==0){
            return 0;
        }
        unordered_map<int,int> mp;
        long long pre=0;
        mp[0]=-1;
        int ans=n;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int currmod=pre%p;
            int tarmod=(currmod-rem+p) % p;
            if(mp.find(tarmod)!=mp.end()){
                ans=min(ans,i-mp[tarmod]);
            }
            mp[currmod]=i;
        }
        return (ans==n) ? -1:ans;
    }
};
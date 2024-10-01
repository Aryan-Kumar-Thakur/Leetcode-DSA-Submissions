class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int rem=arr[i] % k;
            if(rem<0){
                rem+=k;
            }
            mp[rem]++;
        }
        if(mp[0]%2!=0){
            return 0;
        }
        for(int i=1;i<=k/2;i++){
            if(mp[i]!=mp[k-i]){
                return 0;
            }
        }
        return 1;
    }
};
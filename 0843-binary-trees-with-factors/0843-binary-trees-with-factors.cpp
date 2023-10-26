class Solution {
    int mod=1e9+7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_set<int> s(arr.begin(), arr.end());
        unordered_map<int,int> cnt;
        int n=arr.size();
        long long ways=0;
        for(auto it:arr){
            cnt[it]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[j] > sqrt(arr[i])) break;
                if(arr[i] % arr[j]==0){
                    int x = arr[i]/arr[j];
                    if(s.find(x)!=s.end()){
                        long long temp = (long long)cnt[arr[j]] * cnt[x];
                        if(arr[j] == x){
                            cnt[arr[i]]=(cnt[arr[i]] + temp) % mod;
                        }
                        else{
                            cnt[arr[i]] = (cnt[arr[i]] + temp * 2) %mod;
                        }
                    }
                }
            }
        }
        for(auto it:cnt){
            ways=(ways + it.second) % mod;
        }
        return ways;
    }
};
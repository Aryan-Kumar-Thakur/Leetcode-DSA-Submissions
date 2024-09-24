class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp1;
        // unordred_map<int,int> mp2;
        for(auto it:arr1){
            while(it>0){
                if(mp1.find(it)!=mp1.end()){
                    break;
                }
                mp1[it]=1;
                it/=10;
            }
        }
        int ans=0;
        for(auto it:arr2){
            while(it>0){
                if(mp1.find(it)!=mp1.end()){
                    break;
                }
                it/=10;
            }
            int cnt=0;
            while(it>0){
                cnt++;
                it/=10;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
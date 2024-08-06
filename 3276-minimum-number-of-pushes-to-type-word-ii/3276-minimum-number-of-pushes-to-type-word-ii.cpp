class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(auto it:word){
            arr[it-'a']++;
        }
        int ans=0;
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(arr[i]==0) break;
            ans+=(i/8+1)*arr[i];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pre(n+1,0);
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1] ^ arr[i-1];
        }
        vector<int> ans;
        for(auto it:queries){
            int res=pre[it[1]+1] ^ pre[it[0]];
            ans.push_back(res);
        }
        return ans;
    }
};
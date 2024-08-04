class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pre(n,0);
        vector<int> sum;
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            sum.push_back(pre[i]);
            for(int j=0;j<i;j++){
                pre[i]=pre[i]-nums[j];
                sum.push_back(pre[i]);
            }
        }
        int mod=1e9+7;
        sort(sum.begin(),sum.end());
        for(auto it:sum){
            cout<<it<<endl;
        }
        int res=0;
        for(int i=left-1;i<right;i++){
            res=(res%mod + sum[i] % mod) % mod;
        }
        return res;
    }
};
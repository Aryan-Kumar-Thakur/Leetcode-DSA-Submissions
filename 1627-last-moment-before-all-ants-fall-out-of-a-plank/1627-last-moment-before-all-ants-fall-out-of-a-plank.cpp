class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=INT_MIN;
        int N=left.size();
        int M=right.size();
        for(int i=0;i<N;i++){
            ans=max(ans,left[i]-0);
        }
        for(int i=0;i<M;i++){
            ans=max(ans,n-right[i]);
        }
        return ans;
    }
};
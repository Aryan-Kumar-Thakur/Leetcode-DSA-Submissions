class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=INT_MIN;
        int N=left.size();
        int M=right.size();
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        if(N==0){
            return (n-right[0]);
        }
        if(M==0){
            return (left[N-1]-0);
        }
        for(int i=0;i<N;i++){
            int res=INT_MIN;
            int x=left[i]-0;
            for(int j=0;j<M;j++){
                int y=n-right[j];
                int z=INT_MIN;
                if((left[i] > right[j]) && (left[i]-right[j]) % 2 == 0){
                    int l=(left[i]-right[j])/2;
                    z=max(z,abs(l-left[i] + n-left[i]));
                    z=max(z,abs(l-right[j] + right[j]-0));
                }
                res=max(res,max(max(x,y),z));
            }
            ans=max(ans,res);
        }
        return ans;
    }
};
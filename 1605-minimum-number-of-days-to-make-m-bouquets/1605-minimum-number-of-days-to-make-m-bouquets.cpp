class Solution {
    bool solve(vector<int> &arr,long long mid,int m,int k,int n){
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                ans++;
                cnt=0;
            }
        }
        return (ans>=m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        // long long x=(long long)(m*k);
        // if(n < x){
        //     return -1;
        // }
        long long lo=0,hi=1e9+2;
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(solve(bloomDay,mid,m,k,n)){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        if(hi>=1e9+2){
            return -1;
        }
        return hi;
    }
};
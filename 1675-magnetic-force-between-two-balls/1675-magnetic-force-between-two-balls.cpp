class Solution {
public:
bool solve(vector<int>& arr,int mid,int n, int m){
    int cnt=1;
    int st=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-st>=mid){
            cnt++;
            st=arr[i];
        }
    }
    return (cnt>=m);
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int lo=0,hi=1e9+2;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(solve(position,mid,n,m)){
                ans=max(ans,mid);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if(lo>=1e9+2){
            return -1;
        }
        return ans;
    }
};
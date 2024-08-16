class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int maxi=INT_MIN,mini=INT_MAX;
        int n=arr.size();
        int ansarray=-1;
        for(int i=0;i<n;i++){
            if(arr[i][arr[i].size()-1] > maxi){
                maxi=arr[i][arr[i].size()-1] ;
                ansarray=i;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=ansarray && arr[i][0] < mini){
                mini=arr[i][0] ;
            }
        }
        int ans1=maxi-mini;
        maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i][0] < mini){
                mini=arr[i][0] ;
                ansarray=i;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=ansarray && arr[i][arr[i].size()-1] > maxi){
                maxi=arr[i][arr[i].size()-1] ;
            }
        }
        int ans2 = (maxi-mini);
        return max(ans1,ans2);
    }
};
class Solution {
    static bool comp(vector<int> a,vector<int> b){
        return (a[1] <= b[0]);
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // for(auto it:intervals){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        vector<vector<int>> res;
        vector<int> arr(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= arr[1]){
                arr[0]=min(arr[0],intervals[i][0]);
                arr[1]=max(arr[1],intervals[i][1]);
            }
            else{
                res.push_back(arr);
                arr=intervals[i];
            }
        }
        res.push_back(arr);
        return res;
    }
};
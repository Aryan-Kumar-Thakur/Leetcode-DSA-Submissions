class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> minutes(n,0);
        for(int i=0;i<n;i++){
            stringstream ss(timePoints[i]);
            string h,m;
            getline(ss,h,':');
            getline(ss,m,':');
            int totalminutes=(stoi(h) * 60 + stoi(m));
            minutes[i]=totalminutes;
        }
        for(auto it:minutes){
            cout<<it<<" ";
        }
        sort(minutes.begin(),minutes.end());
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,minutes[i]-minutes[i-1]);
        }
        ans=min(ans,1440-minutes[n-1]+minutes[0]);
        return ans;
    }
};
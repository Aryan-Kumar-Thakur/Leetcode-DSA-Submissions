class Solution {
    int findstart(vector<int> &stime,int x,int n){
        int lo=0,hi=n-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(stime[mid]<=x){
                ans=mid+1;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
    int findend(vector<int> &etime,int x,int n){
        int lo=0,hi=n-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(etime[mid]<x){
                ans=mid+1;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> stime;
        vector<int> etime;
        int n=flowers.size();
        for(int i=0;i<n;i++){
            stime.push_back(flowers[i][0]);
            etime.push_back(flowers[i][1]);
        }
        sort(stime.begin(),stime.end());
        sort(etime.begin(),etime.end());
        int m=people.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int x=findstart(stime,people[i],n);
            int y=findend(etime,people[i],n);
            // cout<<x<<" "<<y<<endl;
            ans[i]=max(x-y,0);
        }
        return ans;
    }
};
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        map<int,int> mp;
        int n=dist.size();
        vector<int> time(n,0);
        for(int i=0;i<n;i++){
            if(dist[i]%speed[i] == 0){
                int x=dist[i]/speed[i];
                mp[x]++;
                time[i] = x;
            }
            else{
                int x=dist[i]/speed[i] + 1;
                mp[x]++;
                time[i] = x;
            }
        }
        int cnt=0;
        int ans=0;
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            mp[time[i]]--;
            ans++;
            cnt++;
            if(mp[cnt] >= 1){
                break;
            }
        }
        return ans;
    }
};
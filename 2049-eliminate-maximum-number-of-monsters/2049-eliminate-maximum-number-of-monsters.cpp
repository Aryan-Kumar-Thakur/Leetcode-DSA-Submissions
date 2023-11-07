class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n,0);
        for(int i=0;i<n;i++){
            if(dist[i]%speed[i] == 0){
                int x=dist[i]/speed[i];
                time[i] = x;
            }
            else{
                int x=dist[i]/speed[i] + 1;
                time[i] = x;
            }
        }
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++){
            if(time[i] <= i){
                return i;
            }
        }
        return n;
    }
};
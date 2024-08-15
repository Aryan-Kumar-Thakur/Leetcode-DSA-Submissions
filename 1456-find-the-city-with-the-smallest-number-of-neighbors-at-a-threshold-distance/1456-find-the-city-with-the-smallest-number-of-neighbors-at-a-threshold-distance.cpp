class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(auto it:edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    dis[i][j]=min(dis[i][j],dis[i][via]+dis[via][j]);
                }
            }
        }
        int ans=0;
        int mincnt=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt < mincnt){
                mincnt=cnt;
                ans=i;
            }
            else if(cnt==mincnt){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};
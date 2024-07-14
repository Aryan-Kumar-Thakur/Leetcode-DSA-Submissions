class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int time=0;
        queue<vector<int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int r=f[0];
            int c=f[1];
            int t=f[2];
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc,t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
         return time;
    }
};
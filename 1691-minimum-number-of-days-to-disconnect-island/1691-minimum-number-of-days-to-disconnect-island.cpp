class Solution {
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    bool isvalid(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis){
        return r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && !vis[r][c];
    }
    void dfs(int r,int c,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &vis){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,n,m,grid,vis)){
                dfs(nr,nc,n,m,grid,vis);
            }
        }
    }
    int solve(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        cnt=solve(grid);
        if(cnt==0 || cnt>1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int cnt=solve(grid);
                    if(cnt==0 || cnt>1){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
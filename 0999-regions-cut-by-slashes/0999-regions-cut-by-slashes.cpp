class Solution {
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    bool isvalid(int r,int c,vector<vector<int>> &mat,vector<vector<int>> &vis,int n){
        return r>=0 && r<n && c>=0 && c<n && !vis[r][c] && !mat[r][c];
    }
    void solve(int r,int c,vector<vector<int>> &mat,vector<vector<int>> &vis,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(isvalid(nr,nc,mat,vis,n)){
                solve(nr,nc,mat,vis,n);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size();
        int n=m*3;
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && mat[i][j]==0){
                    ans++;
                    solve(i,j,mat,vis,n);
                }
            }
        }
        return ans;
    }
};
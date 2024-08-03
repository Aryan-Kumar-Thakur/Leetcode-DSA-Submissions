class Solution {
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void solve(int r,int c,int n,int m,vector<vector<int>>& image,int color,int repc){
        image[r][c]=color;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==repc && image[nr][nc]!=color){
                solve(nr,nc,n,m,image,color,repc);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int repc=image[sr][sc];
        solve(sr,sc,n,m,image,color,repc);
        return image;
    }
};
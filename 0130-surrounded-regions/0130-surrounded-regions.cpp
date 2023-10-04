class Solution
{
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};

    void dfs(int r,int c,int n,int m,vector<vector < char>> &board,vector<vector<int>> &visited){
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr >=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !visited[nr][nc]){
                dfs(nr,nc,n,m,board,visited);
            }
        }
    }
    public:
        void solve(vector<vector < char>> &board)
        {
            int n = board.size();
            int m = board[0].size();
            vector<vector < int>> visited(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                if(board[i][0]=='O'){
                    dfs(i, 0, n, m, board, visited);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if(board[i][m-1]=='O'){
                    dfs(i, m-1, n, m, board, visited);
                }
            }
            for (int i = 0; i < m; i++)
            {
                if(board[0][i]=='O'){
                    dfs(0, i, n, m, board, visited);
                }
            }
            for (int i = 0; i < m; i++)
            {
                if(board[n-1][i]=='O'){
                    dfs(n-1, i, n, m, board, visited);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O' && !visited[i][j]){
                        board[i][j]='X';
                    }
                }
            }
        }
};
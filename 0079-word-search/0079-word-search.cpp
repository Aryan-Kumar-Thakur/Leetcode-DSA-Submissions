class Solution {
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    bool solve(int r,int c,int ind,int n,int m,vector<vector<char>>& board, string &word,vector<vector<int>> &visited){
        if(ind >= word.size()){
            return true;
        }
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=r+dr[i];
            int ncol=c+dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[ind] && !visited[nrow][ncol]){
                if(solve(nrow,ncol,ind+1,n,m,board,word,visited)){
                    return true;
                }
            }
        }
        visited[r][c]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> visited(n,vector<int>(m,0));
                    if(solve(i,j,1,n,m,board,word,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
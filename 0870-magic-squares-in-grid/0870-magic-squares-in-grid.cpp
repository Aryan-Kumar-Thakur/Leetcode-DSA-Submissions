class Solution {
    bool solve(vector<vector<int>>& grid,int r,int c){
        set<int> st;
        for(int i=r;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(grid[i][j]>9 || grid[i][j]==0){
                    return false;
                }
                st.insert(grid[i][j]);
            }
        }
        if(st.size()!=9){
            return false;
        }
        vector<int> row;
        vector<int> col;
        vector<int> dig;
        int sum=0;
        int i=r,j=c;
        while(i<r+3 && j<c+3){
            sum+=grid[i][j];
            i++;
            j++;
        }
        dig.push_back(sum);
        sum=0;
        i=r,j=c+2;
        while(i<r+3 && j>=0){
            sum+=grid[i][j];
            i++;
            j--;
        }
        dig.push_back(sum);
        for(int i=r;i<r+3;i++){
            int sum=0;
            for(int j=c;j<c+3;j++){
                sum+=grid[i][j];
            }
            row.push_back(sum);
        }
        for(int i=c;i<c+3;i++){
            int sum=0;
            for(int j=r;j<r+3;j++){
                sum+=grid[j][i];
            }
            col.push_back(sum);
        }
        if(row!=col){
            return false;
        }
        if(dig[0]!=row[0] || dig[1]!=row[0]){
            return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(solve(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
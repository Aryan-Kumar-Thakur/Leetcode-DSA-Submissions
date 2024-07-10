class Solution {
    vector<vector<string>> res;
    bool issafe(vector<string> &ans,int i,int j,int n){
        for(int k=0;k<n;k++){
            if(ans[i][k]=='Q' || ans[k][j]=='Q'){
                return false;
            }
        }
        int x=i,y=j;
        while(x<n && y>=0){
            if(ans[x++][y--]=='Q'){
                return false;
            }
        }
        x=i,y=j;
        while(x<n && y<n){
            if(ans[x++][y++]=='Q'){
                return false;
            }
        }
        x=i,y=j;
        while(x>=0 && y<n){
            if(ans[x--][y++]=='Q'){
                return false;
            }
        }
        x=i,y=j;
        while(x>=0 && y>=0){
            if(ans[x--][y--]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &ans,int ind,int n){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<n;j++){
            if(issafe(ans,ind,j,n)){
                ans[ind][j]='Q';
                solve(ans,ind+1,n);
                ans[ind][j]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i].push_back('.');
            }
        }
        solve(ans,0,n);
        return res;
    }
};
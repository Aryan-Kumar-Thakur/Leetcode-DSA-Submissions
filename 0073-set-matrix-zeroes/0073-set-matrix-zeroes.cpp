class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> ans1;
        vector<int> ans2;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    ans1.push_back(i);
                    ans2.push_back(j);
                }
            }
        }
        for(int i=0;i<ans1.size();i++){
            for(int k=0;k<m;k++){
                matrix[ans1[i]][k]=0;
            }
        }
        for(int i=0;i<ans2.size();i++){
            for(int k=0;k<n;k++){
                matrix[k][ans2[i]]=0;
            }
        }
    }
};
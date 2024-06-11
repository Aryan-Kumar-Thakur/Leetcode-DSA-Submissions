class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1,0);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp[j]=1;
                }
                else{
                    temp[j]=prev[j]+prev[j-1];
                }
            }
            prev=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};
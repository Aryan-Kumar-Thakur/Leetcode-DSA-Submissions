class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target,vector<int> &res,int ind,int n){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<n;i++){
            if (i > ind && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            res.push_back(candidates[i]);
            solve(candidates,target-candidates[i],res,i+1,n);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> res;
        int n=candidates.size();
        solve(candidates,target,res,0,n);
        return ans;
    }
};
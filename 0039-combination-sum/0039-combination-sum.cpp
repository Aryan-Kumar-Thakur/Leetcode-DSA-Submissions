class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target,vector<int> &res,int ind,int n){
        if(target==0){
            ans.push_back(res);
            return;
        }
        if(ind==n || target<0){
            return;
        }
        res.push_back(candidates[ind]);
        solve(candidates,target-candidates[ind],res,ind,n);
        res.pop_back();
        solve(candidates,target,res,ind+1,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        int n=candidates.size();
        solve(candidates,target,res,0,n);
        return ans;
    }
};
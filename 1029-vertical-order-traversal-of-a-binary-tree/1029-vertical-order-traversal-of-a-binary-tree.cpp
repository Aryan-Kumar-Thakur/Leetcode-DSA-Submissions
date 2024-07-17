/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root,map<pair<int,int>,vector<int>> &mp,int vd,int lvl){
        if(!root){
            return;
        }
        mp[{lvl,vd}].push_back(root->val);
        solve(root->left,mp,vd-1,lvl+1);
        solve(root->right,mp,vd+1,lvl+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<pair<int,int>,vector<int>> mp;
        map<int,vector<int>> mp2;
        solve(root,mp,0,0);
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            for(auto i:it.second){
                mp2[it.first.second].push_back(i);
            }
        }
        for(auto it:mp2){
            ans.push_back(it.second);
        }
        return ans;
    }
};
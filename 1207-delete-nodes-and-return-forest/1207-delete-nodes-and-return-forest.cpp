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
    TreeNode* solve(TreeNode* root,vector<TreeNode*> &res,bool f,set<int> &del){
        if(!root){
            return NULL;
        }
        bool isdeleted = del.find(root->val)!=del.end();
        if(f && !isdeleted){
            res.push_back(root);
        }
        root->left=solve(root->left,res,isdeleted,del);
        root->right=solve(root->right,res,isdeleted,del);
        return isdeleted ? NULL:root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> del;
        for(auto it:to_delete){
            del.insert(it);
        }
        vector<TreeNode*> res;
        solve(root,res,1,del);
        return res;
    }
};
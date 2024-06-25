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
     int prev=0;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->right);
        prev+=root->val;
        root->val=prev;
        solve(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){
            return root;
        }
        solve(root);
        return root;
    }
};
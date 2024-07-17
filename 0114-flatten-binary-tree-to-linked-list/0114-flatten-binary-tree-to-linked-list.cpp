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
    TreeNode* find(TreeNode* root){
        if(!root){
            return NULL;
        }
        while(root->right){
            root=root->right;
        }
        return root;
    }
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            TreeNode* succ=find(root->left);
            succ->right=root->right;
            root->right=root->left;
            root->left=NULL;
            solve(root->right);
        }
        else{
            solve(root->right);
        }
    }
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        solve(root);
    }
};
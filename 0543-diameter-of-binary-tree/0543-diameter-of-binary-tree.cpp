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
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> l=solve(root->left);
        pair<int,int> r=solve(root->right);
        pair<int,int> ans;
        ans.first=l.second+r.second;
        ans.second=max(l.second,r.second+1);
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        pair<int,int> ans=solve(root);
        return ans.first;
    }
};
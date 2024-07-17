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
    int maxsum=INT_MIN;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=max(0,solve(root->left));
        int r=max(0,solve(root->right));
        maxsum=max(maxsum,l+r+root->val);
        return max(l,r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return maxsum;
    }
};
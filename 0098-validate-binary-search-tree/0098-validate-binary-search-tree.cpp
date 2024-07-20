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
    bool solve(TreeNode* root,long long int lb,long long int ub){
        if(!root){
            return true;
        }
        if(root->val <= lb || root->val >= ub){
            return false;
        }
        bool l=solve(root->left,lb,root->val);
        bool r=solve(root->right,root->val,ub);
        return (l && r);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        long long int lb=LLONG_MIN;
        long long int ub=LLONG_MAX;
        return solve(root,lb,ub);
    }
};
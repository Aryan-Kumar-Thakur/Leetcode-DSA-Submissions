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
 class Info{
    public:
    int sum;
    bool isbst;
    int mini;
    int maxi;
 };
class Solution {
public:
    int ans=0;
    Info solve(TreeNode* root){
        if(!root){
            return {0,true,INT_MAX,INT_MIN};
        }
        Info left=solve(root->left);
        Info right=solve(root->right);
        Info curr;
        curr.mini=min(left.mini,root->val);
        curr.maxi=max(right.maxi,root->val);
        curr.sum=left.sum+right.sum+root->val;
        if((left.isbst && right.isbst && (root->val > left.maxi && root->val < right.mini))){
            curr.isbst=true;
            ans=max(ans,curr.sum);
        }
        else{
            curr.isbst=false;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return ans;
    }
};
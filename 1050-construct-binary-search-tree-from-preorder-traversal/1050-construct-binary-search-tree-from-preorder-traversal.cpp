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
    int ind=0;
    TreeNode* solve(vector<int> &preorder,int ub,int n){
        if(ind==n || preorder[ind]>ub){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=solve(preorder,root->val,n);
        root->right=solve(preorder,ub,n);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return solve(preorder,INT_MAX,n);
    }
};
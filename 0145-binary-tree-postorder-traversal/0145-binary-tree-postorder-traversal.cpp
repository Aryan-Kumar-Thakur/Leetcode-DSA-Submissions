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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            TreeNode* curr=root->right;
            if(curr){
                while(curr->left && curr->left!=root){
                    curr=curr->left;
                }
                if(curr->left==root){
                    curr->left=NULL;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    curr->left=root;
                    root=root->right;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
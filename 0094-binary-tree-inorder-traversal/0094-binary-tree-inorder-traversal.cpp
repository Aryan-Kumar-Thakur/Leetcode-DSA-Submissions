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
    TreeNode* find(TreeNode* temp,TreeNode* root){
        while(temp->right && temp->right!=root){
            temp=temp->right;
        }
        return temp;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode* succ=find(root->left,root);
                if(succ->right==root){
                    succ->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
                else{
                    succ->right=root;
                    root=root->left;
                }
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};
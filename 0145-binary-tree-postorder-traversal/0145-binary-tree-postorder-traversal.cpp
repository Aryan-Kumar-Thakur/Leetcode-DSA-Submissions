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
        stack<TreeNode*> st;
        vector<int> ans;
        while(true){
            if(root){
                st.push(root);
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                if(st.empty()) break;
                root=st.top();
                st.pop();
                root=root->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
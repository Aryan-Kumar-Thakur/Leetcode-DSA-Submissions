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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool f=0;
        while(!q.empty()){
            vector<int> res;
            int x=q.size();
            while(x--){
                TreeNode* ele=q.front();
                q.pop();
                res.push_back(ele->val);
                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }
            }
            if(f){
                reverse(res.begin(),res.end());
            }
            ans.push_back(res);
            f=!f;
        }
        return ans;
    }
};
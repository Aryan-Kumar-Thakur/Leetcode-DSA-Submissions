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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int x=q.size();
            int mini=q.front().second;
            long long s=0,e=0;
            for(int i=0;i<x;i++){
                TreeNode* ele=q.front().first;
                long long d=q.front().second-mini;
                q.pop();
                if(i==0){
                    s=d;
                }
                if(i==x-1){
                    e=d;
                }
                if(ele->left){
                    q.push({ele->left,2*d});
                }
                if(ele->right){
                    q.push({ele->right,2*d+1});
                }
            }
            ans=max(ans,(int)(e-s+1));
        }
        return ans;
    }
};
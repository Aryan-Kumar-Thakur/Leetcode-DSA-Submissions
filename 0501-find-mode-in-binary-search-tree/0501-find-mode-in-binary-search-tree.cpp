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
    void findcnt(TreeNode* root,map<int,int> &mp){
        if(!root){
            return;
        }
        findcnt(root->left,mp);
        mp[root->val]++;
        findcnt(root->right,mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        findcnt(root,mp);
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        // cout<<maxi<<endl;
        vector<int> ans;
        for(auto it:mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
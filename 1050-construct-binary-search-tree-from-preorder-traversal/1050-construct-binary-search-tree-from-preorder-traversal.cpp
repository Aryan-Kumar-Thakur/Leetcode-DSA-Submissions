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
    int find(vector<int> &preorder,int s,int e){
        for(int i=s+1;i<=e;i++){
            if(preorder[i]>preorder[s]){
                return i;
            }
        }
        return e+1;
    }
    TreeNode* solve(vector<int> &preorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[s]);
        if(s==e){
            return root;
        }
        int ind=find(preorder,s,e);
        root->left=solve(preorder,s+1,ind-1);
        root->right=solve(preorder,ind,e);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return solve(preorder,0,n-1);
    }
};
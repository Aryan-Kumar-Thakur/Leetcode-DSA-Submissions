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
    int find(int val,vector<int> &inorder,int s,int e){
        for(int i=s;i<=e;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return 0;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[ind++]);
        int pos=find(root->val,inorder,s,e);
        root->left=solve(preorder,inorder,s,pos-1);
        root->right=solve(preorder,inorder,pos+1,e);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return solve(preorder,inorder,0,n-1);
    }
};